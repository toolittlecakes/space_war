

#include "planet.h"

void Planet::setup(const Parameters input)
{
	GameObject::setup(input);

	parameters.visible = true;
	parameters.collidable = true;
	parameters.gravitational = true;


}

void Planet::calculate(const std::vector<GameObject*>& objects)
{
	parameters.acceleration = Vector2D::Vector2D(0, 0);
	for (auto it : objects) {
		
		if (it->get_parameters().gravitational && it->get_parameters().name != parameters.name) {

			double distance_x = it->get_parameters().coordinates.x - parameters.coordinates.x;
			double distance_y = it->get_parameters().coordinates.y - parameters.coordinates.y;
			double absolute_distance = Vector2D::Vector2D(distance_x, distance_y).absolute();
			double distance_in_cube = absolute_distance * absolute_distance * absolute_distance;
			double forse_x = it->get_parameters().mass * distance_x / distance_in_cube;
			double forse_y = it->get_parameters().mass * distance_y / distance_in_cube;

			Vector2D additive_acceleration(forse_x, forse_y);

			parameters.acceleration += additive_acceleration * gravitational_constant;
		}
	}

	parameters.speed += parameters.acceleration;
	parameters.coordinates += parameters.speed;


	parameters.angle += parameters.angular_velocity;
}
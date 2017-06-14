
#include "shoot.h"

void Shoot::setup(const Parameters input)
{
	GameObject::setup(input);

	parameters.visible = true;
	parameters.collidable = true;
	parameters.gravitational = false;


}

void Shoot::calculate(const std::vector<GameObject*>& objects)
{
	parameters.coordinates += parameters.speed * speed_factor;

	if (fabs(parameters.coordinates.x) > life_distance || fabs(parameters.coordinates.y) > life_distance)
	{
		parameters.must_be_deleted = true;
	}
}

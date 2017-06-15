
#include <iostream>
#include "output.h"
#include "player.h"


void Player::draw(const double interpolation)
{
	OutputSingleton *out = OutputSingleton::instance();

	
	double factor_x = out->get_resolution_x() / 2 / fabs(parameters.coordinates.x);
	double factor_y = out->get_resolution_y() / 2 / fabs(parameters.coordinates.y);
	
	double factor = 1;
	if (factor_x < 1 && factor_x < factor_y) {
		factor = factor_x * 0.9;
	}
	else if (factor_y < 1) {
		factor = factor_y * 0.9;
	}
	int x = static_cast<int>(parameters.coordinates.x * factor + 0.5) + (out->get_resolution_x() - parameters.size.x) / 2;
	int y = static_cast<int>(parameters.coordinates.y * factor + 0.5) + (out->get_resolution_y() - parameters.size.y) / 2;

	out->apply_surface(x, y, parameters.angle, factor, texture);
}

void Player::setup(const Parameters input)
{
	GameObject::setup(input);

	parameters.visible = true;
	parameters.collidable = true;
	parameters.gravitational = true;
}

void Player::calculate(const std::vector<GameObject*>& objects)
{
	parameters.acceleration = Vector2D::Vector2D(0, 0); // TODO
	
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

void Player::players_actions(std::map<SDL_Keycode, bool>& key_state)
{
	parameters.make_shoot = false;

	if (still_ticks_to_refresh > 0) {
		still_ticks_to_refresh--;
	}

	Vector2D acceleration = get_axis(parameters.player_number, key_state);

	parameters.speed.x += acceleration.y * sin(parameters.angle) * engine_power;
	parameters.speed.y -= acceleration.y * cos(parameters.angle) * engine_power;

	parameters.angular_velocity += acceleration.x * �ontrol_sensitivity;


	if (get_shoot(parameters.player_number, key_state) && still_ticks_to_refresh == 0) {
		parameters.make_shoot = true;
		still_ticks_to_refresh = ticks_refresh_gun;
	}
}


Vector2D Player::get_axis(const size_t number_player, std::map<SDL_Keycode, bool>& key_state)
{
	Vector2D result(0, 0);
	SDL_Keycode up, down, left, right;


	if (number_player == 1) {
		up = SDLK_UP;
		down = SDLK_DOWN;
		right = SDLK_RIGHT;
		left = SDLK_LEFT;
	}
	else if (number_player == 2) {
		up = SDLK_w;
		down = SDLK_s;
		right = SDLK_d;
		left = SDLK_a;
	}


	result.y = static_cast<double> (key_state[up]) - static_cast<double> (key_state[down]);
	result.x = static_cast<double> (key_state[right]) - static_cast<double> (key_state[left]);


	return result;
}

bool Player::get_shoot(const size_t number_player, std::map<SDL_Keycode, bool>& key_state)
{
	if (number_player == 1) {
		return key_state[SDLK_RCTRL];
	}
	else if (number_player == 2) {
		return key_state[SDLK_SPACE];
	}
}

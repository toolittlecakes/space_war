
#include <iostream>
#include "game_object.h"
#include "output.h"





Parameters GameObject::get_parameters()
{
	return parameters;
}

void GameObject::draw(const double interpolation)
{
	int x = static_cast<int>(parameters.coordinates.x + 0.5);
	int y = static_cast<int>(parameters.coordinates.y + 0.5);
	OutputSingleton::instance()->apply_surface(x + 600, y + 300, texture);
}


void GameObject::collide(const std::vector<GameObject*>& objects)
{
}

bool GameObject::setup(Parameters input)
{
	parameters = input;

	texture = LoadImage(parameters.name + ".bmp");
	return true;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

void Player::calculate(const std::vector<GameObject*>& objects)
{
}

void Player::accelerate(Vector2D & acceleration)
{
	
}

void Planet::calculate(const std::vector<GameObject*>& objects)
{
}

void Shoot::calculate(const std::vector<GameObject*>& objects)
{
}

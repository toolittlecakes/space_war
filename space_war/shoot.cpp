
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
	parameters.coordinates += parameters.speed;
}

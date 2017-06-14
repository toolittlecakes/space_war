#include "update.h"
#include "game_object.h"



void Movable::update(const std::vector<GameObject*>& objects)
{
	for (auto it1 : objects)
	{

	}
}



void Controllable::update(const std::vector<GameObject*>&)
{
}

void NotMovable::update(const std::vector<GameObject*>&)
{
}

void Gravitational::update(const std::vector<GameObject*>&)
{
}

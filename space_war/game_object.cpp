
#include <iostream>

#include "game_object.h"
#include "output.h"





Parameters GameObject::get_parameters()
{
	return parameters;
}

void GameObject::draw(const double interpolation)
{
	OutputSingleton *out = OutputSingleton::instance();
	
	int x = static_cast<int>(parameters.coordinates.x + 0.5) + (out->get_resolution_x() - parameters.size.x) / 2;
	int y = static_cast<int>(parameters.coordinates.y + 0.5) + (out->get_resolution_y() - parameters.size.y) / 2;
	
	out->apply_surface(x, y, parameters.angle, texture);
}


void GameObject::collide(const std::vector<GameObject*>& objects)
{
	double my_mesh_rad = (parameters.size.x + parameters.size.y) / 4;
	for (auto it : objects) {
		if (it->get_parameters().collidable && it->get_parameters().name != parameters.name) {
			

			double it_mesh_rad = (it->get_parameters().size.x + it->get_parameters().size.y) / 4;
			double distance = (it->get_parameters().coordinates - parameters.coordinates).absolute();
			if (distance < my_mesh_rad + it_mesh_rad && it->get_parameters().mass > parameters.mass / 100) {
				parameters.must_be_deleted = true;
			}

		}
	}
}

void GameObject::setup(const Parameters input)
{
	parameters = input;

	texture = LoadImage(parameters.name + ".bmp");

	SDL_Rect pos;
	pos.x = static_cast<int>(parameters.coordinates.x + 0.5);
	pos.y = static_cast<int>(parameters.coordinates.y + 0.5);
	SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);

	parameters.size.x = pos.w;
	parameters.size.y = pos.h;

	parameters.must_be_deleted = false;
	parameters.make_shoot = false;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}






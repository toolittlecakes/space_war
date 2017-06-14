#pragma once

#include <istream>
#include <string>
#include <SDL.h>
#include "vector2d.h"
#include "load_image.h"

struct Parameters final {

	std::string name;
	double mass;
	Vector2D size;
	Vector2D coordinates;
	Vector2D speed;
	Vector2D acceleration;
	size_t player_number;
	SDL_Texture* texture;

	Parameters() {};
	Parameters(std::istream &data);
	~Parameters();
};
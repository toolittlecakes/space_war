
#include <iostream>
#include "output.h"
#include "parameters.h"


Parameters::Parameters(std::istream & data)
{
	data >> this->name >> this->mass >> this->size.x >> this->size.y
		>> this->coordinates.x >> this->coordinates.y
		>> this->speed.x >> this->speed.y 
		>> this->acceleration.x >> this->acceleration.y >> this->player_number;
	this->texture = LoadImage(this->name + ".bmp"); //TODO delete
	this->acceleration.x = this->acceleration.y = 0;
}

Parameters::~Parameters()
{
	SDL_DestroyTexture(this->texture);
}

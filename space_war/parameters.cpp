
#include <iostream>
#include "output.h"
#include "parameters.h"


Parameters::Parameters(std::istream & data)
{
	data >> name >> mass
		>> coordinates.x >> coordinates.y
		>> speed.x >> speed.y 
		>> acceleration.x >> acceleration.y 
		>> angle >> angular_velocity 
		>> player_number;
}



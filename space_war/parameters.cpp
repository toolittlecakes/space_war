
#include <iostream>
#include "output.h"
#include "parameters.h"


Parameters::Parameters(std::istream & data)
{
	data >> name >> mass >> size.x >> size.y
		>> coordinates.x >> coordinates.y
		>> speed.x >> speed.y 
		>> acceleration.x >> acceleration.y >> player_number;
}



#include "drowing.h"
#include "game_object.h"
#include "output.h"

void Visibility::drow(const double interpolation)
{
	int x = static_cast<int>(object->parameters.coordinates.x + 0.5);
	int y = static_cast<int>(object->parameters.coordinates.y + 0.5);
	OutputSingleton::instance()->apply_surface(x+600, y+300, object->parameters.texture);

}

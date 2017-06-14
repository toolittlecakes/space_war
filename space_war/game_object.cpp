
#include <iostream>
#include "game_object.h"
#include "output.h"



bool GameObject::setup(Parameters input)
{
	parameters = input;
	_c->setup(this);
	_v->setup(this);
	_u->setup(this);
	return true;
}

GameObject::~GameObject()
{
	delete _v;
	delete _u;
	delete _c;
}




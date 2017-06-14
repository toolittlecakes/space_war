#pragma once
#include <vector>
#include <map>
#include <SDL.h>


#include "parameters.h"

class GameObject {
private:

protected:
	Parameters parameters;
	SDL_Texture *texture;

	const double gravitational_constant = 0.0001;
public:
	virtual Parameters get_parameters();
	GameObject() {};
	
	virtual void draw(const double interpolation); // draw, if parameters.visible
	virtual void calculate(const std::vector<GameObject *> &objects) {};
	virtual void collide(const std::vector<GameObject *> &objects); // collide, if parameters.collidable
	virtual void players_actions(std::map<SDL_Keycode, bool> & key_state) {}; // by user input

	virtual void setup(const Parameters input); //setup parameters and load image

	virtual ~GameObject();
};




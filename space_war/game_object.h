#pragma once
#include <vector>
#include <SDL.h>


#include "parameters.h"

class GameObject {
private:

protected:
	Parameters parameters;
	SDL_Texture *texture;
public:
	virtual Parameters get_parameters();
	GameObject() {};
	
	virtual void draw(const double interpolation); // draw, if parameters.visible
	virtual void update(const std::vector<GameObject *> &objects) {};
	virtual void collide(const std::vector<GameObject *> &objects); // collide, if parameters.collidable

	virtual bool setup(Parameters input); //setup parameters and load image

	virtual ~GameObject();
};

class Player : public GameObject {
public:
	Player() {};

	virtual void update(const std::vector<GameObject *> &objects) override;
};

class Planet : public GameObject {
public:
	Planet() {};

	virtual void update(const std::vector<GameObject *> &objects) override;
};

class Shoot : public GameObject {
public:
	Shoot() {};


	virtual void update(const std::vector<GameObject *> &objects) override;
};
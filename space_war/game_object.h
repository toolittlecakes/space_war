#pragma once
#include <vector>
#include <SDL.h>


#include "collision.h"
#include "drowing.h"
#include "update.h"
#include "input.h"
#include "vector2d.h"
#include "parameters.h"
class GameObject {
private:
	VisibilityDelegate *_v;
	UpdateDelegate *_u;
	CollisionDelegate *_c;

protected:
	
	
public:
	Parameters parameters;
	GameObject(VisibilityDelegate *v, UpdateDelegate *u, CollisionDelegate *c)
		: _v(v), _u(u), _c(c) {}

	void drow(const double interpolation) { _v->drow(interpolation); }
	void update(const std::vector<GameObject *> &objects) { _u->update(objects); } //аргументы можно занести в конструктор
	void collide(const std::vector<GameObject *> &objects) { _c->collide(objects); }
	
	virtual bool setup(Parameters input);

	virtual ~GameObject() = 0;
};

class Player : public GameObject {
public:
	Player() : GameObject(new Visibility(), new Controllable(), new Solid()) {}
	virtual ~Player() override {};
};

class Planet : public GameObject {
public:
	Planet() : GameObject(new Visibility(), new Gravitational(), new Solid()) {}
	virtual ~Planet() override {};
};

class Shoot : public GameObject {
	Shoot() : GameObject(new Visibility(), new Movable(), new Solid()) {}
	virtual ~Shoot() override {};
};
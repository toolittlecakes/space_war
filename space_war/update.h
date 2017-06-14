#pragma once
#include <vector>

//#include "vector2d.h"

class GameObject;

class UpdateDelegate {
protected:
	GameObject *object;
public:
	UpdateDelegate() {}
	virtual void setup(GameObject *_object) { object = _object; }	

	virtual void update(const std::vector<GameObject *> &) = 0;
	virtual ~UpdateDelegate() {};
};

class NotMovable : public UpdateDelegate {
public:
	NotMovable() {}
	virtual void update(const std::vector<GameObject *> &) override;
	virtual ~NotMovable() override {};
};

class Movable : public UpdateDelegate { //without forse
public:
	Movable() {}
	virtual void update(const std::vector<GameObject *> &) override;
	virtual ~Movable() override {};
};

class Gravitational : public Movable {
public:
	Gravitational() {}
	virtual void update(const std::vector<GameObject *> &) override; //как вызвать update для movable?
	virtual ~Gravitational() override {};

};

class Controllable : public Gravitational {
public:
	Controllable() {}
	virtual void update(const std::vector<GameObject *> &) override; //как вызвать update для movable?
	virtual ~Controllable() override {};

};

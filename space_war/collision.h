#pragma once
#include <vector>
//#include "vector2d.h"
class GameObject;

class CollisionDelegate {
protected:
	GameObject *object;
public:
	CollisionDelegate() {}
	virtual void setup(GameObject *_object) { object = _object; }

	virtual void collide(const std::vector<GameObject *> & objects) = 0;
	virtual ~CollisionDelegate() {};
};

class NotSolid : public CollisionDelegate {
public:
	NotSolid() {}
	virtual void collide(const std::vector<GameObject *> & objects) {};
	virtual ~NotSolid() {};

};

class Solid : public CollisionDelegate {
public:
	Solid() {}
	virtual void collide(const std::vector<GameObject *> & objects) {};
	virtual ~Solid() {
		object = nullptr;
	};

};

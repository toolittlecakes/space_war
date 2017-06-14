#pragma once
#include <vector>
//#include "Parameters.h"

class GameObject;

class VisibilityDelegate {
protected:
	GameObject *object;
public:
	VisibilityDelegate() {};
	virtual void setup(GameObject *_object) { object = _object; }

	virtual void drow(double interpolation) = 0;
	virtual ~VisibilityDelegate() {};
};


class Invisibility : public VisibilityDelegate {
public:
	Invisibility() {}

	virtual void drow(double interpolation) override {};
	virtual ~Invisibility() override {};
};

class Visibility : public VisibilityDelegate {
public:
	Visibility() {}

	virtual void drow(double interpolation) override;
	virtual ~Visibility() override {};
};
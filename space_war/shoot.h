#pragma once

#include "game_object.h"

class Shoot : public GameObject {
public:
	Shoot() {};

	virtual void setup(const Parameters input) override;
	virtual void calculate(const std::vector<GameObject *> &objects) override;
};
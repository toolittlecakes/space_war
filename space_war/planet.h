#pragma once

#include "game_object.h"

class Planet : public GameObject {
public:
	Planet() {};

	virtual void setup(const Parameters input) override;
	virtual void calculate(const std::vector<GameObject *> &objects) override;
};

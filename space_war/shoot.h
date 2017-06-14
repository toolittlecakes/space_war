#pragma once

#include "game_object.h"

class Shoot : public GameObject {
private:
	const double life_distance = 1000;
	const double speed_factor = 0.2;
public:
	Shoot() {};

	virtual void setup(const Parameters input) override;
	virtual void calculate(const std::vector<GameObject *> &objects) override;
};
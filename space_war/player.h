#pragma once

#include "game_object.h"

class Player : public GameObject {
private:
	const double engine_power = 0.6;
	const double ñontrol_sensitivity = 0.003;

	Vector2D get_axis(const size_t number_player, std::map<SDL_Keycode, bool>& key_state);
	bool get_shoot(const size_t number_player, std::map<SDL_Keycode, bool>& key_state);
public:
	Player() {};

	virtual void setup(const Parameters input) override;
	virtual void calculate(const std::vector<GameObject *> &objects) override;
	virtual void players_actions(std::map<SDL_Keycode, bool> & key_state) override;
};

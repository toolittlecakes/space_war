#pragma once
#include <istream>
#include "game_object.h"
#include "input.h"

class Game final {
private:
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	std::vector<GameObject *> game_objects;

	bool game_is_running;

	unsigned long GetTickCount();
	GameObject* create_object(std::string &, Parameters &);
	
	Input input;

	void players_actions(std::map<SDL_Keycode, bool> & key_state);
	bool calculate_game();
	bool display_game(const double interpolation);
	bool collide_game();
	void game_events();
public:
	bool setup(std::istream& input_data);
	void run();
};
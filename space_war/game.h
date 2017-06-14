#pragma once
#include <istream>
#include "game_object.h"

class Game final {
private:
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	std::vector<Player*> players;
	std::vector<GameObject *> game_objects;

	bool game_is_running;

	unsigned long GetTickCount();
	GameObject* create_object(std::string &, std::istream &);


	bool update_game();
	bool display_game(const double interpolation);
	bool collide_game();
public:
	void setup(std::istream& input_data);
	void run();
};
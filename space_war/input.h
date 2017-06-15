#pragma once
#include <SDL.h>
#include <vector>
#include <map>

#include "vector2d.h"

class Input final {
private:
	
	std::vector<SDL_Event> events;
	std::map<SDL_Keycode, bool> key_state;
protected:
	
public:
	Input() {};
	
	void refresh();
	bool get_exit();
	bool get_restart();
	std::map<SDL_Keycode, bool> & get_key_state() { return key_state; }
	~Input() {};
};



#include <iostream>
#include "input.h"
#include "vector2d.h"

void Input::refresh() {
	SDL_Event event;
	events.clear();
	while (SDL_PollEvent(&event)) {
		events.push_back(event);

		switch (event.type) {
		case SDL_KEYDOWN:
			key_state[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			key_state[event.key.keysym.sym] = false;
			break;
		}
	}
}

bool Input::get_exit()
{
		return key_state[SDLK_ESCAPE];
}

Vector2D Input::get_axis(const size_t number_player)
{
	Vector2D result(0, 0);
	SDL_Keycode up, down, left, right;
	

	if (number_player == 1) {
		up = SDLK_UP;
		down = SDLK_DOWN;
		right = SDLK_RIGHT;
		left = SDLK_LEFT;
	}
	else if (number_player == 2) {
		up = SDLK_w;
		down = SDLK_s;
		right = SDLK_d;
		left = SDLK_a;
	}


	result.x = static_cast<double> (key_state[up]) - static_cast<double> (key_state[down]);
	result.x = static_cast<double> (key_state[right]) - static_cast<double> (key_state[left]);
	return result;
}


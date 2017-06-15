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

bool Input::get_restart()
{
	return key_state[SDLK_BACKSPACE];
}


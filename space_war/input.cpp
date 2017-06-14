#include <iostream>
#include "input.h" 

InputSingleton* InputSingleton::_self = nullptr;
int InputSingleton::_refcount = 0;


void InputSingleton::refresh() {
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

bool InputSingleton::get_exit()
{
		return key_state[SDLK_ESCAPE];
}

double InputSingleton::get_axis(size_t number_player, std::string orientation)
{
	double result = 0.0;
	SDL_Keycode key1, key2;
	if (number_player == 0 && orientation == "vertical") {
		key1 = SDLK_UP;
		key2 = SDLK_DOWN;
	}
	else if (number_player == 0 && orientation == "horizontal") {
		key1 = SDLK_RIGHT;
		key2 = SDLK_LEFT;
	}

	if (number_player == 1 && orientation == "vertical") {
		key1 = SDLK_w;
		key2 = SDLK_s;
	}
	else if (number_player == 1 && orientation == "horizontal") {
		key1 = SDLK_d;
		key2 = SDLK_a;
	}

	result = static_cast<double> (key_state[key1]) - static_cast<double> (key_state[key2]);

	return result;
}

InputSingleton* InputSingleton::instance()
{
	if (!_self) _self = new InputSingleton();
	return _self;
}

void InputSingleton::free_inst()
{
	{
		_refcount--;
		if (!_refcount) {
			delete this;
			_self = nullptr;
		}
	}
}

InputSingleton::InputSingleton()
{
}

InputSingleton::~InputSingleton()
{
}

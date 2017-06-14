#pragma once
#include <SDL.h>
#include <vector>
#include <map>


class InputSingleton final {
private:
	static InputSingleton* _self;
	static int _refcount;
	
	std::vector<SDL_Event> events;
	std::map<SDL_Keycode, bool> key_state;
protected:
	InputSingleton();
	~InputSingleton();
public:
	static InputSingleton* instance();
	void free_inst();


	void refresh();
	double get_axis(size_t number_player, std::string orientation);
	bool get_exit();
};



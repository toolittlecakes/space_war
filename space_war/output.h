#pragma once
#include <SDL.h>


class OutputSingleton final {
private:
	static OutputSingleton* _self;
	static int _refcount;

	SDL_Window *win;
	
	SDL_Texture *background;
protected:
	OutputSingleton();
	~OutputSingleton();
public:
	SDL_Renderer *ren;
	static OutputSingleton* instance();
	void free_inst();

	SDL_Renderer *get_renderer() { return ren; }
	
	bool refresh_background();
	bool setup();
	bool apply_surface(int x, int y, SDL_Texture *tex);
};

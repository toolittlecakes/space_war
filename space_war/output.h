#pragma once
#include <SDL.h>


class OutputSingleton final {
private:
	static OutputSingleton* _self;
	static int _refcount;

	SDL_Window *win;
	
	SDL_Texture *background;

	const int resolution_x = 1200;
	const int resolution_y = 600;
protected:
	OutputSingleton();
	~OutputSingleton();
public:
	int get_resolution_x() { return resolution_x; };
	int get_resolution_y() { return resolution_y; };
	SDL_Renderer *ren;
	static OutputSingleton* instance();
	void free_inst();

	SDL_Renderer *get_renderer() { return ren; }
	
	bool refresh_background();
	bool setup();
	bool apply_surface(int x, int y, SDL_Texture *tex);
	bool apply_surface(int x, int y, double angle, SDL_Texture *tex);
	bool apply_surface(int x, int y, double angle, double scale, SDL_Texture *tex);
};

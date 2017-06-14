
#include <iostream>
#include <string>
#include "output.h"
#include "load_image.h"

OutputSingleton* OutputSingleton::_self = nullptr;
int OutputSingleton::_refcount = 0;



bool OutputSingleton::refresh_background()
{
	apply_surface(0, 0, background);
	return true;
}

bool OutputSingleton::setup()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}
	atexit(SDL_Quit);

	win = SDL_CreateWindow("Space War!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resolution_x, resolution_y, /*SDL_WINDOW_FULLSCREEN ||*/ SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	std::string file_background = "background.bmp";
	background = LoadImage(file_background);
	if (background == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}
}

bool OutputSingleton::apply_surface(int x, int y, SDL_Texture * tex)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, nullptr, nullptr, &pos.w, &pos.h);


	SDL_RenderCopy(ren, tex, nullptr, &pos);
	return true;
}

bool OutputSingleton::apply_surface(int x, int y, double angle, SDL_Texture * tex)
{
	SDL_Rect pos, rotozoom;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, nullptr, nullptr, &pos.w, &pos.h);

	SDL_RenderCopyEx(ren, tex, nullptr, &pos, angle * 180 / M_PI, nullptr, SDL_FLIP_NONE);
	return true;
}

bool OutputSingleton::apply_surface(int x, int y, double angle, double scale, SDL_Texture * tex)
{
	SDL_Rect pos, rotozoom;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, nullptr, nullptr, &pos.w, &pos.h);

	pos.x = static_cast<int>(x) - (pos.w * scale - pos.w) / 2;
	pos.y = static_cast<int>(y) - (pos.h * scale - pos.h) / 2;
	pos.w = static_cast<int> (pos.w * scale);
	pos.h = static_cast<int> (pos.h * scale);

	SDL_RenderCopyEx(ren, tex, nullptr, &pos, angle * 180 / M_PI, nullptr, SDL_FLIP_NONE);
	return true;
}


OutputSingleton * OutputSingleton::instance()
{
	if (!_self) _self = new OutputSingleton();
	return _self;
}

void OutputSingleton::free_inst()
{
	{
		_refcount--;
		if (!_refcount) {
			delete this;
			_self = nullptr;
		}
	}
}



OutputSingleton::OutputSingleton()
{
}

OutputSingleton::~OutputSingleton()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
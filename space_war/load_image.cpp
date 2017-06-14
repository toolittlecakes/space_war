
#include "load_image.h"
#include "output.h"

SDL_Texture* LoadImage(std::string &filename)
{
	SDL_Surface *loadedImage = nullptr;
	SDL_Texture *texture = nullptr;
	loadedImage = SDL_LoadBMP(filename.c_str());
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(OutputSingleton::instance()->get_renderer(), loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else {
		//std::cout << SDL_GetError() << std::endl;
	}
	return texture;
}



#include <iostream>
#include<string>
#include "load_image.h"
#include "output.h"

SDL_Texture* LoadImage(const std::string &filename)
{
	SDL_Surface *loadedImage = nullptr;
	SDL_Texture *texture = nullptr;
	loadedImage = SDL_LoadBMP(filename.c_str());

	if (loadedImage != nullptr) {
		SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0xff, 0, 0xFF));

		SDL_RenderClear(OutputSingleton::instance()->ren);
		texture = SDL_CreateTextureFromSurface(OutputSingleton::instance()->ren, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else {
		std::cout << SDL_GetError() << std::endl;
	}
	return texture;
}

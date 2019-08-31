#pragma once

#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "../colors/color.h"
using namespace std;

struct Resources
{
	static TTF_Font* font_verdana_12px;
	static TTF_Font* font_verdana_11px;

	static TTF_Font* font_lato_regular_25px;
	static TTF_Font* font_lato_12px;

	static SDL_Surface* texture_systemExit;
	static SDL_Surface* texture_systemCollapse;
	static SDL_Surface* texture_systemExpand;

	static void init();
	static void clear();
};
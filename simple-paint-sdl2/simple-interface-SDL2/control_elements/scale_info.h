#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "../color_scheme/color.h"

using namespace std;

class ScaleInfo
{
private:
	double scale;

	SDL_Renderer* renderer;
	SDL_Texture* parent_target;
	SDL_Rect size;
	TTF_Font* font;

public:
	ScaleInfo(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, double scale, string font, int font_size);
	~ScaleInfo();
public:
	void update();
	void set_scale(double scale);
};
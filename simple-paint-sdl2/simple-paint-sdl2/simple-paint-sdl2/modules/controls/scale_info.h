#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
#include "../colors/color.h"

using namespace std;

class Viewport;

class ScaleInfo
{
private:
	double scale;

	SDL_Renderer* renderer;
	Viewport* parent;

	SDL_Texture* texture;
	SDL_Texture* text_texture;

	SDL_Rect size;
	TTF_Font* font;

	bool is_updated;

public:
	ScaleInfo(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size, double scale, string font, int font_size);
	~ScaleInfo();

private:
	void init();

public:
	void update_();
	void update();
	void set_scale(double scale);
};
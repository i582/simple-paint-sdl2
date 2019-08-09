#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../colors/color.h"

using namespace std;

class _Control
{
protected:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Rect size;

	string text;
	TTF_Font* font;
	int font_size;
	int align;

	bool blocked;
	bool display;

public:
	_Control(SDL_Renderer* renderer, SDL_Rect size, string text, string font, int font_size);
	virtual ~_Control();

public:
	virtual void update() = 0;

	virtual void mouseButtonDown(SDL_Event* e) = 0;
	virtual void mouseButtonUp(SDL_Event* e) = 0;
	virtual void mouseMotion(SDL_Event* e) = 0;

	void block();
	void unlock();
	bool is_block();

	void show();
	void hide();
	bool is_show();

	bool is_hover(int x, int y);
};
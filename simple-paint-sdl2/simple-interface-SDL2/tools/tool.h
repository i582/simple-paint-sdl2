#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "../color_scheme/color.h"

enum TOOLS
{
	NULL_TOOLS
};

class Tool 
{
private:
	SDL_Renderer* renderer;
	SDL_Rect sizes;
	SDL_Texture* icon;

	bool hover;
	bool selected;
	
public:
	Tool(SDL_Renderer* renderer, int x, int y);

public:
	void render();

	void set_hover(bool value);
	void set_selected(bool value);

	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);

	bool on_hover(int x, int y);
};
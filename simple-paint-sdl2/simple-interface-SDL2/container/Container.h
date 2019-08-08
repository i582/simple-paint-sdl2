#pragma once
#include "SDL.h"
#include "iostream"
#include "../color_scheme/color.h"

using namespace std;

class ContainerVScroll;

class Container
{
private:
	SDL_Renderer* renderer;
	SDL_Rect size;

	SDL_Texture* texture;

	ContainerVScroll* v_scroll;

	SDL_Point pos_mouse;

public:
	Container(SDL_Renderer* renderer, SDL_Rect size);

public:
	friend ContainerVScroll;

public:
	void setup();

	void update();
	void update_coord(int* x, int* y);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);

	bool on_hover(int x, int y);
};
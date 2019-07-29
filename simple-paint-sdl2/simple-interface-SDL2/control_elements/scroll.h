#pragma once

#include "SDL.h"
#include "iostream"
#include "vector"
#include "../color_scheme/color.h"

class Viewport;

class Scroll {
private:
	SDL_Renderer* renderer;

	SDL_Rect body_size;
	SDL_Rect slider_size;

	int max_value;
	int now_value;
	int step_size;

	bool is_focus;

	Viewport* parent;

public:
	Scroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size);

public:
	void update();

	void set_viewport(Viewport* parent);
	void set_step(int step);

	bool body_hover(int x, int y);
	bool slider_hover(int x, int y);

	bool on_focus();

	double get_value();
	void set_value(double value);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);

};
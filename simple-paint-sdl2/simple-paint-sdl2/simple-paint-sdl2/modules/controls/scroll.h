#pragma once

#include "SDL.h"
#include "iostream"
#include "vector"
#include "../colors/color.h"

using namespace std;

class Scroll 
{
protected:
	SDL_Renderer* renderer;
	SDL_Event e;

	SDL_Rect body_size;
	SDL_Rect slider_size;

	int max_value;
	int now_value;
	int step_size;

	bool is_focus;

	bool display;

public:
	Scroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size);

public:
	virtual void update() = 0;
	virtual void set_step(int step) = 0;

	void hide();
	void show();
	bool is_show();

	bool body_hover(int x, int y);
	bool slider_hover(int x, int y);

	bool on_focus();

	double get_value();
	void set_value(double value);

	virtual void shift(int delta) = 0;

	virtual void on_event() = 0;

	virtual void mouseButtonDown(SDL_Event* e) = 0;
	virtual void mouseButtonUp(SDL_Event* e) = 0;
	virtual void mouseMotion(SDL_Event* e) = 0;

};
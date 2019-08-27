#pragma once

#include "scroll.h"

class HScroll : public Scroll
{
private:

public:
	HScroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size);

public:
	void set_step(int step);
	void shift(int delta);

	virtual void update() = 0;

	void on_event();

	virtual void mouseButtonDown(SDL_Event* e) = 0;
	virtual void mouseButtonUp(SDL_Event* e) = 0;
	virtual void mouseMotion(SDL_Event* e) = 0;
};
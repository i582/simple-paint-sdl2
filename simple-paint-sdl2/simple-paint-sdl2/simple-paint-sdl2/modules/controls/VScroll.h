#pragma once

#include "scroll.h"

class VScroll : public Scroll
{
private:

public:
	VScroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size);

public:
	void set_step(int step);
	void shift(int delta);

	virtual void update() = 0;

	virtual void mouseButtonDown(SDL_Event* e) = 0;
	virtual void mouseButtonUp(SDL_Event* e) = 0;
	virtual void mouseMotion(SDL_Event* e) = 0;
};
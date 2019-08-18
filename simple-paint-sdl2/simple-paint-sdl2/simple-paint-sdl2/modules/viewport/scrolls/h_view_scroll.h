#pragma once

#include "../../controls/hscroll.h"

class Viewport;

class H_ViewScroll : public HScroll
{
private:
	Viewport* parent;

public:
	H_ViewScroll(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size, double now_value, int max_value, int step_size);

public:
	void update();
	void update_scroll_pos();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
};
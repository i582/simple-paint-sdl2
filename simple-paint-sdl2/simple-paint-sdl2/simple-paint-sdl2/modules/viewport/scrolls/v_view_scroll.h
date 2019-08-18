#pragma once

#include "../../controls/vscroll.h"

class Viewport;

class V_ViewScroll : public VScroll
{
private:
	Viewport* parent;

public:
	V_ViewScroll(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size, double now_value, int max_value, int step_size);

public:
	void update();
	void update_scroll_pos();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
};
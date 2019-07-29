#pragma once

#include "../control_elements/vscroll.h"

class Viewport;

class V_ViewScroll : public VScroll
{
private:
	Viewport* parent;

public:
	V_ViewScroll(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size, int now_value, int max_value, int step_size);

public:
	void update();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
};
#pragma once
#include "../control_elements/VScroll.h"

class Container;

class ContainerVScroll : public VScroll
{
private:
	Container* parent;

public:
	ContainerVScroll(SDL_Renderer* renderer, Container* parent, SDL_Rect size, int now_value, int max_value, int step_size);
	
public:
	void update();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
};


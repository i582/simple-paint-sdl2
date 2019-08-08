#pragma once
#include "tools/tool.h"

class Toolbar
{
private:
	SDL_Renderer* renderer;
	SDL_Rect sizes;
	SDL_Rect sizes_one_tool;

	int selected_tool;

public:
	Toolbar(SDL_Renderer* renderer);

private:
	void init();

public:
	void update();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);

	/* Вспомогательные */
	bool on_hover(int x, int y);

	int get_tool();
};
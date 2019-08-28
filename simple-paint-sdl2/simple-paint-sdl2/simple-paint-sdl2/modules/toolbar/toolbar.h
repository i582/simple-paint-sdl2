#pragma once
#include "tools/tool.h"
#include "vector"

#include "../window/window.h"

using namespace std;

class Toolbar
{
private:
	Window* parent;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect size;

	vector <Tool*> tools;

	SDL_Point mouse_coord;

public:
	Toolbar(Window* parent, SDL_Rect size);
	~Toolbar();

private:
	void init();

public:
	void update();
	void render_tools();
	
	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);

	/* Вспомогательные */
	bool on_hover(int x, int y);

	int get_tool();

	void update_coord(int* x, int* y);
};
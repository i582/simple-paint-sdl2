#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../../colors/color.h"
#include "../../primitives/primitives.h"

#include "layers/layers.h"

using namespace std;

class WorkTable;

class Canvas {
private:
	SDL_Rect size;

	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Layers* layers;

	SDL_Point pos_mouse;

	WorkTable* parent;


	bool is_selected;
	int selected_id;

public:
	Canvas(SDL_Renderer* renderer, WorkTable* parent, SDL_Rect size);
	~Canvas();

private:
	void init();

public:
	void update();

	/* События */
	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void keyDown(SDL_Event* e);

	/* Вспомогательные */
	bool on_hover(int x, int y);

	bool full_in_viewport();

	bool get_selected();
	Layers* get_layers();

	void update_coord(int* x, int* y);
};
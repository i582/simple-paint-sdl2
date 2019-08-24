#pragma once

#include "../viewport/canvas/layers/layers.h"
#include "layer_view/layer_view.h"
#include "../colors/color.h"

class Viewport;

class LayersViewer
{
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect size;
	Layers* layers;

	vector <LayerView*> layer_views;

	SDL_Point pos_mouse;

	TTF_Font* font;

	Viewport* parent;

public:
	LayersViewer(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size);

public:
	friend LayerView;

private:
	void setup();
	void render_one_layer(int num);

public:
	void update();
	void update_layer();

	bool on_hover(int x, int y);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);

	void update_coord(int* x, int* y);
};
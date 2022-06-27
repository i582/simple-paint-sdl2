#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"

#include "../../viewport/canvas/layers/layers.h"
#include "../../colors/color.h"
#include "../../controls/Checkbox.h"

using namespace std;

class LayersViewer;

class LayerView
{
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect size;
	TTF_Font* font;

	Layers* layers;
	int layer_id;

	LayersViewer* parent;

	Checkbox* eye_checkbox;
	Checkbox* block_checkbox;
	
	SDL_Point pos_mouse;

public:
	LayerView(SDL_Renderer* renderer, LayersViewer* parent, int layer_id, SDL_Rect size, Layers* layers);
	~LayerView();

private:
	void setup();

public:
	void update();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);

	int get_layer_id();
	bool layer_is_show();
	bool layer_is_blocked();
	bool on_hover(int x, int y);

	void update_coord(int* x, int* y);
};


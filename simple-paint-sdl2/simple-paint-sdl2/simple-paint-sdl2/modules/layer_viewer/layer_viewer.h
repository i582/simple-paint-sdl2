#pragma once

#include "../viewport/canvas/layers/layers.h"
#include "../colors/color.h"

class LayerViewer
{
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect size;
	Layers* layers;

	TTF_Font* font;

public:
	LayerViewer(SDL_Renderer* renderer, SDL_Rect size, Layers* layers);

private:
	void render();

	void render_one_layer(int num);

public:
	void update();

};
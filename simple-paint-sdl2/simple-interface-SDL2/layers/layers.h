#pragma once
#include "SDL.h"
#include "iostream"
#include "vector"

#include "../layer/layer.h"

using namespace std;


class Layers
{
private:
	SDL_Renderer* renderer;
	vector <Layer*> layers;
	SDL_Rect main_size;

public:
	Layers(SDL_Renderer* renderer, SDL_Rect main_size);

public:
	void add(Layer* layer);

	SDL_Texture* ready_texture();

	int get_size();
	int get_upper_layer_id();
	int get_upper_layer_id_in_point(int x, int y);

	Layer* at(int index);
	
};
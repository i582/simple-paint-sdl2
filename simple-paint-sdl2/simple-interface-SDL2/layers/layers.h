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

public:
	Layers(SDL_Renderer* renderer);

public:
	void add(Layer* layer);

	SDL_Texture* ready_texture();
};
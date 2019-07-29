#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"

class Layer
{
public:
	SDL_BlendMode blend_mode;
	Uint8 alpha;
	SDL_Texture* texture;

	Layer(SDL_Texture* texture, Uint8 alpha = 0xFF, SDL_BlendMode blend_mode = SDL_BLENDMODE_BLEND)
	{
		this->alpha = alpha;
		this->texture = texture;
		this->blend_mode = blend_mode;
	}

	void set_alpha(Uint8 alpha) {
		this->alpha = alpha;
	}

	void set_blend_mode(SDL_BlendMode blend_mode) {
		this->blend_mode = blend_mode;
	}
};
#include "layers.h"

Layers::Layers(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void Layers::add(Layer* layer)
{
	layers.push_back(layer);
}

SDL_Texture* Layers::ready_texture()
{
	int width;
	int height;
	SDL_QueryTexture(layers.at(0)->texture, NULL, NULL, &width, &height);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	
	SDL_SetRenderTarget(renderer, texture);

	for (auto& layer : layers)
	{
		//SDL_SetRenderDrawBlendMode(renderer, layer->blend_mode);
		SDL_SetTextureBlendMode(layer->texture, layer->blend_mode);
		SDL_SetTextureAlphaMod(layer->texture, layer->alpha);
		SDL_RenderCopy(renderer, layer->texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, NULL);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	return texture;
}

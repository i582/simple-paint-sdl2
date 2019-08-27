#include "layers.h"
#include "ctime"

Layers::Layers(SDL_Renderer* renderer, SDL_Rect main_size)
{
	this->renderer = renderer;
	this->main_size = main_size;
	this->texture = nullptr;
	this->layers = {};

	init();
}

void Layers::init()
{
	this->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, main_size.w, main_size.h);
}

void Layers::add(Layer* layer)
{
	layers.push_back(layer);
}

SDL_Texture* Layers::ready_texture()
{
	int width = main_size.w;
	int height = main_size.h;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_SetRenderTarget(renderer, texture);

	for (auto& layer : layers)
	{
		if (!layer->display)
			continue;

		src.x = -layer->size.x > 0 ? -layer->size.x : 0;
		src.y = -layer->size.y > 0 ? -layer->size.y : 0;
		src.w = layer->size.w + layer->size.x > main_size.w ? main_size.w : layer->size.w + layer->size.x;
		src.h = layer->size.h + layer->size.y > main_size.h ? main_size.h : layer->size.h + layer->size.y;

		dst.x = layer->size.x > 0 ? layer->size.x : 0;
		dst.y = layer->size.y > 0 ? layer->size.y : 0;
		dst.w = layer->size.w + layer->size.x < width ? layer->size.w + layer->size.x : width;
		dst.h = layer->size.h + layer->size.y < height ? layer->size.h + layer->size.y : height;

		SDL_SetTextureBlendMode(layer->texture, layer->blend_mode);
		SDL_SetTextureAlphaMod(layer->texture, layer->alpha);



		SDL_RenderCopy(renderer, layer->texture, &src, &dst);
		SDL_RenderPresent(renderer);
	}

	
	SDL_SetRenderTarget(renderer, NULL);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


	return texture;
}

SDL_Texture* Layers::layer_view(int id)
{
	int width = main_size.w;
	int height = main_size.h;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_SetRenderTarget(renderer, texture);


	src.x = -layers.at(id)->size.x > 0 ? -layers.at(id)->size.x : 0;
	src.y = -layers.at(id)->size.y > 0 ? -layers.at(id)->size.y : 0;
	src.w = layers.at(id)->size.w + layers.at(id)->size.x > main_size.w ? main_size.w : layers.at(id)->size.w + layers.at(id)->size.x;
	src.h = layers.at(id)->size.h + layers.at(id)->size.y > main_size.h ? main_size.h : layers.at(id)->size.h + layers.at(id)->size.y;

	dst.x = layers.at(id)->size.x > 0 ? layers.at(id)->size.x : 0;
	dst.y = layers.at(id)->size.y > 0 ? layers.at(id)->size.y : 0;
	dst.w = layers.at(id)->size.w + layers.at(id)->size.x < width ? layers.at(id)->size.w + layers.at(id)->size.x : width;
	dst.h = layers.at(id)->size.h + layers.at(id)->size.y < height ? layers.at(id)->size.h + layers.at(id)->size.y : height;

	SDL_SetTextureBlendMode(layers.at(id)->texture, SDL_BLENDMODE_NONE);
	SDL_SetTextureAlphaMod(layers.at(id)->texture, 0xFF);

	SDL_RenderCopy(renderer, layers.at(id)->texture, &src, &dst);

	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, NULL);

	return texture;
}

int Layers::get_size()
{
	return layers.size();
}

SDL_Rect Layers::get_size_layers()
{
	return main_size;
}

int Layers::get_upper_layer_id()
{
	int i;
	for (i = layers.size() - 1; i >= 0 && layers.at(i)->is_block() && !layers.at(i)->is_show(); i--);
	return i;
}

int Layers::get_upper_layer_id_in_point(int x, int y)
{
	int i;
	SDL_Point p = { x, y };
	for (i = layers.size() - 1; i >= 0 &&
		(layers.at(i)->is_block() || !layers.at(i)->is_show() || !SDL_PointInRect(&p, &layers.at(i)->size)); i--);
	return i;
}

Layer* Layers::at(int index)
{
	return layers.at(index);
}

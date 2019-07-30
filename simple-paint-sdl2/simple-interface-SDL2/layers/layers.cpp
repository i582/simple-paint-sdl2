#include "layers.h"
#include "ctime"

Layers::Layers(SDL_Renderer* renderer, SDL_Rect main_size)
{
	this->renderer = renderer;
	this->main_size = main_size;
}

void Layers::add(Layer* layer)
{
	layers.push_back(layer);
}

SDL_Texture* Layers::ready_texture()
{
	//time_t start = clock();

	int width;
	int height;
	SDL_QueryTexture(layers.at(0)->texture, NULL, NULL, &width, &height);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	
	SDL_Rect src;
	SDL_Rect dst;

	SDL_SetRenderTarget(renderer, texture);

	for (auto& layer : layers)
	{
		if (!layer->is_display())
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
	}

	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, NULL);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


	//time_t end = clock();
	//cout << "time equal " << (end - start) / 1000. << endl;

	return texture;
}

int Layers::get_size()
{
	return layers.size();
}

int Layers::get_upper_layer_id()
{
	int i;
	for (i = layers.size() - 1; i >= 0 && layers.at(i)->is_block(); i--);
	return i;
}

int Layers::get_upper_layer_id_in_point(int x, int y)
{
	int i;
	SDL_Point p = { x, y };
	for (i = layers.size() - 1; i >= 0 &&
		(layers.at(i)->is_block() || !SDL_PointInRect(&p, &layers.at(i)->size)); i--);
	
	return i;
}

Layer* Layers::at(int index)
{
	return layers.at(index);
}

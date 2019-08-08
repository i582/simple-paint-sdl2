#include "layer_viewer.h"
#include "../primitives/primitives.h"
#include "ctime"

LayerViewer::LayerViewer(SDL_Renderer* renderer, SDL_Rect size, Layers* layers)
{
	this->renderer = renderer;
	this->size = size;
	this->layers = layers;


	TTF_Init();
	font = TTF_OpenFont("./fonts/verdana.ttf", 11);

	this->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, size.w, size.h);

	// set-up primitives
	Primitives::renderer = renderer;
}

void LayerViewer::render()
{
	SDL_SetRenderTarget(renderer, texture);

	// body
	Primitives::fill_rect(NULL, Colors::element_background);
	Primitives::rect(NULL, Colors::viewport_border);
	//

	for (int i = 0; i < layers->get_size(); i++)
	{
		render_one_layer(i);
	}


	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void LayerViewer::render_one_layer(int num)
{
	int height = 35;

	SDL_Rect layer_size = { 0, height * num, size.w, height };

	// draw body
	Primitives::fill_rect(&layer_size, Colors::element_background);
	Primitives::rect(&layer_size, Colors::viewport_border);
	//

	// draw text
	SDL_Surface* text_surface = TTF_RenderUTF8_Blended(font, layers->at(num)->name.c_str(), Colors::element_text);
	SDL_Rect text_rect = { 70, height * num + (height - text_surface->h) / 2., text_surface->w, text_surface->h };
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_FreeSurface(text_surface);
	SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
	SDL_DestroyTexture(text_texture);
	//

	// draw layer view
	SDL_Rect layers_size = layers->get_size_layers();
	double aspect_ratio = layers_size.h / layers_size.w;
	SDL_Rect layer_view = { 40, 8 + height * num, 20 * aspect_ratio, 20 * (1 / aspect_ratio) };
	Primitives::fill_rect(&layer_view, Colors::white);
	SDL_Texture* view = layers->layer_view(num);

	SDL_SetRenderTarget(renderer, texture);

	SDL_RenderCopy(renderer, view, NULL, &layer_view);
	SDL_DestroyTexture(view);
	//


	

}

void LayerViewer::update()
{
	render();

	SDL_RenderCopy(renderer, texture, NULL, &size);
	SDL_RenderPresent(renderer);
}

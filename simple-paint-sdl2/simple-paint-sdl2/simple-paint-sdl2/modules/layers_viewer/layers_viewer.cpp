#include "layers_viewer.h"
#include "../primitives/primitives.h"
#include "../viewport/viewport.h"
#include "ctime"

LayersViewer::LayersViewer(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size, Layers* layers)
{
	this->renderer = renderer;
	this->parent = parent;
	this->size = size;
	this->layers = layers;

	setup();
}

void LayersViewer::setup()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);

	
	Primitives::renderer = renderer;

	for (int i = 0; i < layers->get_size(); i++)
	{
		layer_views.push_back(new LayerView(renderer, this, i, { 0, 35 * i - ((i == 0) ? 0 : 1 * i), size.w, 35 }, layers));
	}

	
}

void LayersViewer::update()
{
	SDL_SetRenderTarget(renderer, texture);

	// body
	Primitives::fill_rect(NULL, Colors::element_background);
	Primitives::rect(NULL, Colors::viewport_border);
	//

	for (auto& layer_view : layer_views)
	{
		layer_view->update();
	}


	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);

	SDL_RenderCopy(renderer, texture, NULL, &size);
	SDL_RenderPresent(renderer);
}

void LayersViewer::update_layer()
{
	for (auto& layer_view : layer_views)
	{
		int layer_id = layer_view->get_layer_id();
		layers->at(layer_id)->display = layer_view->layer_is_show();

		layers->at(layer_id)->blocked = layer_view->layer_is_blocked();
	}
}

bool LayersViewer::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { size.x, size.y, size.w, size.h };
	return SDL_PointInRect(&p, &r);
}

void LayersViewer::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	for (auto& layer_view : layer_views)
	{
		if (layer_view->on_hover(pos_mouse.x, pos_mouse.y))
		{
			layer_view->mouseButtonDown(e);
		}
	}
}

void LayersViewer::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	for (auto& layer_view : layer_views)
	{
		if (layer_view->on_hover(pos_mouse.x, pos_mouse.y))
		{
			layer_view->mouseButtonUp(e);

			update_layer();

			update();
			parent->update();
		}

	}
	

}

void LayersViewer::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	for (auto& layer_view : layer_views)
	{
		if (layer_view->on_hover(pos_mouse.x, pos_mouse.y))
		{
			layer_view->mouseMotion(e);
		}
	}
}

void LayersViewer::mouseWheel(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

}

void LayersViewer::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

void LayersViewer::render_one_layer(int num)
{
	int height = 35;

	SDL_Rect layer_size = { 0, height * num, size.w, height };

	// draw body
	Primitives::fill_rect(&layer_size, Colors::element_background);
	Primitives::rect(&layer_size, Colors::viewport_border);
	//

	// draw text
	SDL_Surface* text_surface = TTF_RenderUTF8_Blended(font, layers->at(num)->name.c_str(), Colors::element_text);
	SDL_Rect text_rect = { 70, (int)(height * num + (long)(height - text_surface->h) / 2.), text_surface->w, text_surface->h };
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_FreeSurface(text_surface);
	SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
	SDL_DestroyTexture(text_texture);
	//

	// draw layer view
	SDL_Rect layers_size = layers->get_size_layers();
	double aspect_ratio = layers_size.h / layers_size.w;
	SDL_Rect layer_view = { 40, (int)(8 + height * num), (int)(20 * aspect_ratio), (int)(20 * (1. / aspect_ratio)) };
	Primitives::fill_rect(&layer_view, Colors::white);
	SDL_Texture* view = layers->layer_view(num);

	SDL_SetRenderTarget(renderer, texture);

	SDL_RenderCopy(renderer, view, NULL, &layer_view);
	SDL_DestroyTexture(view);
	//

}

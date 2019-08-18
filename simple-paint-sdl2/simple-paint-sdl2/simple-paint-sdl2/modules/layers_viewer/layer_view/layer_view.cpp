#include "layer_view.h"
#include "../layers_viewer.h"

#include "ctime"
LayerView::LayerView(SDL_Renderer* renderer, LayersViewer* parent, int layer_id, SDL_Rect size, Layers* layers)
{
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);

	this->renderer = renderer;

	this->parent = parent;

	this->size = size;
	this->layers = layers;
	this->layer_id = layer_id;

	this->font = TTF_OpenFont("././resources/fonts/verdana.ttf", 11);

	setup();
}

LayerView::~LayerView()
{
	SDL_DestroyTexture(texture);
}

void LayerView::setup()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);
	
	eye_checkbox = new Checkbox(renderer, texture, { 0, 0, 35, 35 }, EYE, true);
	block_checkbox = new Checkbox(renderer, texture, { size.w - 35, 0, 35, 35 }, BLOCK, false);
}

void LayerView::update()
{
	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, Colors::element_background.r, Colors::element_background.g, Colors::element_background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);
	SDL_SetRenderDrawColor(renderer, Colors::viewport_border.r, Colors::viewport_border.g, Colors::viewport_border.b, 0xFF);
	SDL_RenderDrawRect(renderer, NULL);

	

	// draw text
	SDL_Surface* text_surface = TTF_RenderUTF8_Blended(font, layers->at(layer_id)->name.c_str(), Colors::element_text);
	SDL_Rect text_rect = { 80, (int)((size.h - text_surface->h) / 2.), text_surface->w, text_surface->h };
	SDL_Texture * text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_FreeSurface(text_surface);
	SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
	SDL_DestroyTexture(text_texture);
	// 


	// draw layer view
	SDL_Rect layers_size = layers->get_size_layers();
	double aspect_ratio = layers_size.w / layers_size.h;

	SDL_Rect layer_rect = { 45, 8, -1, -1 };
	
	layer_rect.w = (int)(20 * aspect_ratio);
	layer_rect.h = 20;
	
	if (layer_rect.w > 35)
	{
		layer_rect.h /= layer_rect.w / 35;
		layer_rect.w = 35;
	}
	

	SDL_Texture* layer_texture = layers->layer_view(layer_id);
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, layer_texture, NULL, &layer_rect);
	SDL_DestroyTexture(layer_texture);
	//


	// draw eye
	SDL_SetRenderTarget(renderer, texture);
	eye_checkbox->update();
	//
	block_checkbox->update();


	SDL_SetRenderTarget(renderer, parent->texture);
	SDL_RenderCopy(renderer, texture, NULL, &size);
	SDL_SetRenderTarget(renderer, NULL);
}

void LayerView::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

}

void LayerView::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	if (eye_checkbox->is_hover(pos_mouse.x, pos_mouse.y))
	{
		eye_checkbox->mouseButtonUp(e);
	}

	if (block_checkbox->is_hover(pos_mouse.x, pos_mouse.y))
	{
		block_checkbox->mouseButtonUp(e);
	}
}

void LayerView::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);
	
}

int LayerView::get_layer_id()
{
	return layer_id;
}

bool LayerView::layer_is_show()
{
	return eye_checkbox->is_checked();
}

bool LayerView::layer_is_blocked()
{
	return block_checkbox->is_checked();
}

bool LayerView::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &size);
}

void LayerView::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

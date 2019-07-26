#include "scroll.h"
#include "../viewport/viewport.h"

Scroll::Scroll(SDL_Renderer* renderer, int width,
	int height, int x, int y, int now_value, int max_value, 
	int size_one_step)
{
	this->renderer = renderer;

	sizes.w = width;
	sizes.h = height;
	sizes.x = x;
	sizes.y = y;

	slider_sizes.w = width - 4;
	slider_sizes.h = height * (double)((double)size_one_step / (double)max_value);
	slider_sizes.x = x + 2;
	slider_sizes.y = height * (double)((double)now_value / (double)max_value) - slider_sizes.h - 2;

	this->max_value = max_value;
	this->now_value = now_value;
	this->size_one_step = size_one_step;

	this->is_push = false;

	
}

void Scroll::render()
{
	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_SetRenderDrawColor(renderer, Colors::scroll_back.r, Colors::scroll_back.g, Colors::scroll_back.b, 0xFF);
	SDL_RenderFillRect(renderer, &sizes);

	SDL_SetRenderDrawColor(renderer, Colors::scroll_slider.r, Colors::scroll_slider.g, Colors::scroll_slider.b, 0xFF);
	SDL_RenderFillRect(renderer, &slider_sizes);

	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void Scroll::set_parent(Viewport* parent)
{
	this->parent = parent;
}

bool Scroll::v_scroll_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &sizes);
}

bool Scroll::v_slider_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &slider_sizes);
}

void Scroll::mouseButtonDown(SDL_Event* event)
{
	is_push = true;
}

void Scroll::mouseButtonUp(SDL_Event* event)
{
	is_push = false;
}

void Scroll::mouseMotion(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);

	if (is_push)
	{
		/*if (v_slider_hover(pos_mouse.x, pos_mouse.y)) 
		{*/
			slider_sizes.y = pos_mouse.y - slider_sizes.h / 2;
			
			render();
			parent->update();
		//}
	}
}

void Scroll::update_coord(int* x, int* y)
{
	*x -= parent->x;
	*y -= parent->y;
}

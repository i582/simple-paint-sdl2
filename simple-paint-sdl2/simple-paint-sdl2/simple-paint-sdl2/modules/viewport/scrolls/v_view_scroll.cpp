#include "v_view_scroll.h"
#include "../viewport.h"

V_ViewScroll::V_ViewScroll(SDL_Renderer* renderer, Viewport* parent,
	SDL_Rect size, int now_value, int max_value, int step_size) 
	: VScroll(renderer, size, now_value, max_value, step_size)
{
	this->parent = parent;
}

void V_ViewScroll::update()
{

	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_SetRenderDrawColor(renderer, Colors::scroll_back.r, Colors::scroll_back.g, Colors::scroll_back.b, 0xFF);
	SDL_RenderFillRect(renderer, &body_size);

	if (display)
	{
		SDL_SetRenderDrawColor(renderer, Colors::scroll_slider.r, Colors::scroll_slider.g, Colors::scroll_slider.b, 0xFF);
		SDL_RenderFillRect(renderer, &slider_size);
	}

	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void V_ViewScroll::update_scroll_pos()
{
	int new_y = parent->canvas->get_y();
	double procents = (parent->height / 2. - parent->canvas->get_height() / 2. - new_y) / (double)parent->canvas->get_height();
	set_value(procents);
}

void V_ViewScroll::mouseButtonDown(SDL_Event* e)
{
	is_focus = true;

	int pos_x = e->motion.x;
	int pos_y = e->motion.y;
	parent->update_coord(&pos_x, &pos_y);

	if (!slider_hover(pos_x, pos_y))
	{
		if (slider_size.y < 0)
			slider_size.y = 0;

		if (slider_size.y > body_size.h - slider_size.h)
			slider_size.y = body_size.h - slider_size.h;

		slider_size.y = pos_y;
		now_value = (int)((slider_size.y / (double)body_size.h) * max_value);
	}
}

void V_ViewScroll::mouseButtonUp(SDL_Event * e)
{
	is_focus = false;
}

void V_ViewScroll::mouseMotion(SDL_Event * e)
{
	if (is_focus)
	{
		slider_size.y += e->motion.yrel;

		if (slider_size.y < 0)
			slider_size.y = 0;

		if (slider_size.y > body_size.h - slider_size.h)
			slider_size.y = body_size.h - slider_size.h;

		now_value = (int)((slider_size.y / ((double)body_size.h - slider_size.h)) * max_value);


		double procent = this->get_value();
		int new_y = (int)(parent->height / 2 - parent->canvas->get_height() / 2 - procent * parent->canvas->get_height());
		parent->canvas->set_position(parent->canvas->get_x(), new_y);

		parent->update();
	}
}

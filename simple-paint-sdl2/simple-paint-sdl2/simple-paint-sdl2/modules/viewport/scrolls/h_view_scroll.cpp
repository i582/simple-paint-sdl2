#include "h_view_scroll.h"
#include "../viewport.h"

H_ViewScroll::H_ViewScroll(SDL_Renderer* renderer, Viewport* parent,
	SDL_Rect size, int now_value, int max_value, int step_size)
	: HScroll(renderer, size, now_value, max_value, step_size)
{
	this->parent = parent;
}

void H_ViewScroll::update()
{

	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_SetRenderDrawColor(renderer, Colors::scroll_back.r, Colors::scroll_back.g, Colors::scroll_back.b, 0xFF);
	SDL_RenderFillRect(renderer, &body_size);

	if (display)
	{
		SDL_SetRenderDrawColor(renderer, Colors::scroll_slider.r, Colors::scroll_slider.g, Colors::scroll_slider.b, 0xFF);
		SDL_RenderFillRect(renderer, &slider_size);
	}

	SDL_SetRenderDrawColor(renderer, Colors::scroll_corner.r, Colors::scroll_corner.g, Colors::scroll_corner.b, 0xFF);
	SDL_Rect corner = { body_size.w + body_size.x, body_size.y, body_size.h, body_size.h };
	SDL_RenderFillRect(renderer, &corner);

	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void H_ViewScroll::update_scroll_pos()
{
	int new_x = parent->canvas->get_x();
	double x_procent = ((parent->width / 2. - parent->canvas->get_width() / 2.) - new_x) / (double)parent->canvas->get_width();
	set_value(x_procent);
}

void H_ViewScroll::mouseButtonDown(SDL_Event* e)
{
	is_focus = true;

	int pos_x = e->motion.x;
	int pos_y = e->motion.y;
	parent->update_coord(&pos_x, &pos_y);

	if (!slider_hover(pos_x, pos_y))
	{
		if (slider_size.x < 0)
			slider_size.x = 0;

		if (slider_size.x > body_size.w - slider_size.w)
			slider_size.x = body_size.w - slider_size.w;

		slider_size.x = (int)(pos_x - slider_size.w / 2.);
		now_value = (int)((slider_size.x / (double)body_size.w) * max_value);
	}
}

void H_ViewScroll::mouseButtonUp(SDL_Event * e)
{
	is_focus = false;
}

void H_ViewScroll::mouseMotion(SDL_Event * e)
{
	if (is_focus)
	{
		slider_size.x += e->motion.xrel;

		if (slider_size.x < body_size.x)
			slider_size.x = body_size.x;

		if (slider_size.x > body_size.w - slider_size.w + body_size.x)
			slider_size.x = body_size.w - slider_size.w + body_size.x;

		now_value = (int)((slider_size.x / ((double)body_size.w - slider_size.w)) * max_value);

		double procent = this->get_value();
		int new_x = (int)(parent->width / 2 - parent->canvas->get_width() / 2 - procent * parent->canvas->get_width());
		parent->canvas->set_position(new_x, parent->canvas->get_y());

		parent->update();
	}
}


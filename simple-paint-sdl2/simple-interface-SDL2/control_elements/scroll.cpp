#include "scroll.h"
#include "../viewport/viewport.h"

Scroll::Scroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size)
{
	this->renderer = renderer;
	this->body_size = size;

	slider_size.w = body_size.w - 4;
	slider_size.h = body_size.h * (step_size / (double)max_value);
	slider_size.x = body_size.x + 2;
	slider_size.y = body_size.h * (now_value / (double)max_value) - slider_size.h / 2;

	this->max_value = max_value;
	this->now_value = now_value;
	this->step_size = step_size;

	this->is_focus = false;
}

void Scroll::update()
{
	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_SetRenderDrawColor(renderer, Colors::scroll_back.r, Colors::scroll_back.g, Colors::scroll_back.b, 0xFF);
	SDL_RenderFillRect(renderer, &body_size);

	SDL_SetRenderDrawColor(renderer, Colors::scroll_slider.r, Colors::scroll_slider.g, Colors::scroll_slider.b, 0xFF);
	SDL_RenderFillRect(renderer, &slider_size);

	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void Scroll::set_viewport(Viewport* parent)
{
	this->parent = parent;
}

void Scroll::set_step(int step)
{
	this->step_size = step;

	slider_size.h = body_size.h * (step_size / (double)max_value);
	slider_size.y = body_size.h * (now_value / (double)max_value) - slider_size.h / 2;
}

bool Scroll::body_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &body_size);
}

bool Scroll::slider_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &slider_size);
}

bool Scroll::on_focus()
{
	return is_focus;
}

/**
 * return {-1 to 1}
 */
double Scroll::get_value()
{
	return (now_value / (double)max_value - 0.5) * 2;
}

/**
 * Value is {-1 to 1}
 */
void Scroll::set_value(double value)
{
	now_value = (value / 2. + 0.5) * max_value;
	update();
}

void Scroll::mouseButtonDown(SDL_Event* e)
{
	is_focus = true;

	int pos_x = e->motion.x;
	int pos_y = e->motion.y;
	parent->update_coord(&pos_x, &pos_y);

	if (!slider_hover(pos_x, pos_y))
	{
		slider_size.y = pos_y - slider_size.h / 2.;
		now_value = (slider_size.y / (double)body_size.h) * max_value;

		if (slider_size.y < 0)
			slider_size.y = 0;

		if (slider_size.y > body_size.h - slider_size.h)
			slider_size.y = body_size.h - slider_size.h;
	}
}

void Scroll::mouseButtonUp(SDL_Event* e)
{
	is_focus = false;
}

void Scroll::mouseMotion(SDL_Event* e)
{
	if (is_focus)
	{
		slider_size.y += e->motion.yrel;

		if (slider_size.y < 0)
			slider_size.y = 0;

		if (slider_size.y > body_size.h - slider_size.h)
			slider_size.y = body_size.h - slider_size.h;

		now_value = ((double)slider_size.y / ((double)body_size.h - slider_size.h)) * max_value;
		cout << now_value << endl;
	}
}

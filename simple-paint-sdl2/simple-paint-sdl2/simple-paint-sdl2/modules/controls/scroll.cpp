#include "scroll.h"

Scroll::Scroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size)
{
	this->renderer = renderer;
	this->body_size = size;

	this->max_value = max_value;
	this->now_value = now_value;
	this->step_size = step_size;

	this->is_focus = false;
	this->display = false;
}

void Scroll::hide()
{
	display = false;
	update();
}

void Scroll::show()
{
	display = true;
	update();
}

bool Scroll::is_show()
{
	return display;
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
	now_value = (int)((value / 2. + 0.5) * max_value);
	update();
}

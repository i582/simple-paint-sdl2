#include "VScroll.h"

VScroll::VScroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size)
	: Scroll(renderer, size, now_value, max_value, step_size)
{
	slider_size.w = body_size.w - 4;
	slider_size.h = body_size.h * (step_size / (double)max_value);
	slider_size.x = body_size.x + 2;
	slider_size.y = body_size.h * (now_value / (double)max_value) - slider_size.h / 2;
}

void VScroll::set_step(int step)
{
	this->step_size = step;

	slider_size.h = body_size.h * (step_size / (double)max_value);
	slider_size.y = body_size.h * (now_value / (double)max_value) - slider_size.h / 2;
}

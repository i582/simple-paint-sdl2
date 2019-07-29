#include "HScroll.h"

HScroll::HScroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size)
	: Scroll(renderer, size, now_value, max_value, step_size)
{
	slider_size.w = body_size.w * (step_size / (double)max_value);
	slider_size.h = body_size.h - 4;

	slider_size.x = body_size.w * (now_value / (double)max_value) - slider_size.w / 2;
	slider_size.y = body_size.y + 2;

	return;
}

void HScroll::set_step(int step)
{
	this->step_size = step;

	slider_size.w = body_size.w * (step_size / (double)max_value);
	slider_size.x = body_size.w * (now_value / (double)max_value) - slider_size.w / 2;
}

#include "HScroll.h"

HScroll::HScroll(SDL_Renderer* renderer, SDL_Rect size, int now_value, int max_value, int step_size)
	: Scroll(renderer, size, now_value, max_value, step_size)
{
	slider_size.w = (int)(body_size.w * (step_size / (double)max_value));
	slider_size.h = (int)(body_size.h - 4);

	slider_size.x = (int)(body_size.w * (now_value / (double)max_value) - slider_size.w / 2);
	slider_size.y = (int)(body_size.y + 2);

	return;
}

void HScroll::set_step(int step)
{
	this->step_size = step;

	slider_size.w = (int)(body_size.w * (step_size / (double)max_value));
	slider_size.x = (int)(body_size.w * (now_value / (double)max_value) - slider_size.w / 2);
}

void HScroll::shift(int delta)
{
	slider_size.x += delta;

	if (slider_size.x < 0) slider_size.x = 0;
	if (slider_size.x + slider_size.w > body_size.w) slider_size.x = body_size.w - slider_size.w;

	now_value = (int)((slider_size.x / ((double)body_size.w - slider_size.w)) * max_value);

	update();
}

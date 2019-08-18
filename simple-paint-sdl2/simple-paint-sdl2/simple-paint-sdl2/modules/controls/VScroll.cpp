#include "VScroll.h"

VScroll::VScroll(SDL_Renderer* renderer, SDL_Rect size, double now_value, int max_value, int step_size)
	: Scroll(renderer, size, now_value, max_value, step_size)
{
	slider_size.w = (int)(body_size.w - 4);
	slider_size.h = (int)(body_size.h * (step_size / (double)max_value));
	slider_size.x = (int)(body_size.x + 2);
	slider_size.y = (int)((body_size.h - slider_size.h) * now_value + body_size.y);
}

void VScroll::set_step(int step)
{
	step_size = step;

	slider_size.h = (int)(body_size.h * (step_size / (double)max_value));
	slider_size.y = (int)((body_size.h - slider_size.h) * now_value + body_size.y);
}

void VScroll::shift(int delta)
{
	slider_size.y += delta;

	if (slider_size.y < 0) slider_size.y = 0;
	if (slider_size.y + slider_size.h > body_size.h) slider_size.y = body_size.h - slider_size.h;

	now_value = slider_size.y / ((double)body_size.h - slider_size.h);
	
	update();
}

void VScroll::on_event()
{
	while (SDL_WaitEvent(&e) && is_focus)
	{
		switch (e.type)
		{

		case SDL_MOUSEMOTION:
		{
			mouseMotion(&e);
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			mouseButtonDown(&e);
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			mouseButtonUp(&e);
			break;
		}
		}
	}
}

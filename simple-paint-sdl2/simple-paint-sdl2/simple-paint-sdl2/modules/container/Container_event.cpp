#include "Container.h"
#include "ContainerVScroll.h"

void Container::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	if (v_scroll->slider_hover(pos_mouse.x, pos_mouse.y) && v_scroll->is_show())
	{
		v_scroll->mouseButtonDown(e);
		return;
	}
}

void Container::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	if (v_scroll->slider_hover(pos_mouse.x, pos_mouse.y) && v_scroll->is_show())
	{
		v_scroll->mouseButtonUp(e);
		return;
	}
}

void Container::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	if (v_scroll->on_focus() && v_scroll->is_show())
	{
		v_scroll->mouseMotion(e);
		v_scroll->on_event();

		update();

		return;
	}
}

void Container::mouseWheel(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);

	if (v_scroll->is_show())
	{
		if (e->wheel.y > 0)
		{
			v_scroll->shift(-10);
		}
		else if (e->wheel.y < 0)
		{
			v_scroll->shift(10);
		}

		/*double procent = v_scroll->get_value();
		int new_y = (int)(this->height / 2. - canvas->get_height() / 2. - procent * canvas->get_height());
		canvas->set_position(canvas->get_x(), new_y);*/

		update();
	}
}
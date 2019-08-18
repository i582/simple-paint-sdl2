#include "viewport.h"

void Viewport::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


	if (v_scroll->slider_hover(pos_mouse.x, pos_mouse.y) && v_scroll->is_show() && h_scroll->is_show())
	{
		v_scroll->mouseButtonDown(e);
		v_scroll->on_event();
		return;
	}
	
	if (h_scroll->slider_hover(pos_mouse.x, pos_mouse.y) && v_scroll->is_show() && h_scroll->is_show())
	{
		h_scroll->mouseButtonDown(e);
		h_scroll->on_event();
		return;
	}


	

	if (canvas->on_hover(pos_mouse.x, pos_mouse.y) || canvas->get_selected())
	{
		canvas->mouseButtonDown(e);
		update();
	}
}

void Viewport::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);



	if (canvas->on_hover(pos_mouse.x, pos_mouse.y) || canvas->get_selected())
	{
		canvas->mouseButtonUp(e);
		layers_viewer->update();
		update();
	}
}

void Viewport::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


	if (canvas->on_hover(pos_mouse.x, pos_mouse.y) || canvas->get_selected())
	{
		canvas->mouseMotion(e);

		if (canvas->get_selected())
			update();
	}

	
}

void Viewport::mouseWheel(SDL_Event* e)
{
	if (SDL_GetModState() & KMOD_ALT)
	{
		SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
		update_coord(&pos_mouse.x, &pos_mouse.y);

		if (e->wheel.y > 0)
		{
			if (size_factor > 5)
				size_factor += 3;
			else if (size_factor > 3)
				size_factor += 1;
			else if (size_factor < 0.5)
				size_factor += 0.01;
			else
				size_factor += 0.1;
		}
		else if (e->wheel.y < 0)
		{
			if (size_factor > 5)
				size_factor -= 3;
			else if (size_factor > 3)
				size_factor -= 1;
			else if (size_factor < 0.5)
				size_factor -= 0.01;
			else
				size_factor -= 0.1;
		}

		set_canvas_size_factor(size_factor);

		scale_info->set_scale(size_factor);

		setup_scrolls();
		update();

	}
	else if (SDL_GetModState() & KMOD_CTRL && v_scroll->is_show() && h_scroll->is_show())
	{
		if (e->wheel.y > 0)
		{
			h_scroll->shift(-10);
		}
		else if (e->wheel.y < 0)
		{
			h_scroll->shift(10);
		}

		double procent = h_scroll->get_value();
		int new_x = (int)(this->width / 2. - canvas->get_width() / 2. - procent * canvas->get_width());
		canvas->set_position(new_x, canvas->get_y());

		update();
	}
	else if (v_scroll->is_show() && h_scroll->is_show())
	{
		if (e->wheel.y > 0)
		{
			v_scroll->shift(-10);
		}
		else if (e->wheel.y < 0)
		{
			v_scroll->shift(10);
		}

		double procent = v_scroll->get_value();
		int new_y = (int)(this->height / 2. - canvas->get_height() / 2. - procent * canvas->get_height());
		canvas->set_position(canvas->get_x(), new_y);

		update();
	}
	
}

void Viewport::keyDown(SDL_Event* e)
{
}

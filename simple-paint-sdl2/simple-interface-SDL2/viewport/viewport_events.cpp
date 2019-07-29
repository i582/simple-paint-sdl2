#include "viewport.h"

void Viewport::mouseButtonDown(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


	if (v_scroll->slider_hover(pos_mouse.x, pos_mouse.y) && v_scroll->is_show() && h_scroll->is_show())
	{
		v_scroll->mouseButtonDown(event);
		return;
	}
	
	if (h_scroll->slider_hover(pos_mouse.x, pos_mouse.y) && v_scroll->is_show() && h_scroll->is_show())
	{
		h_scroll->mouseButtonDown(event);
		return;
	}




	if (canvas->on_hover(pos_mouse.x, pos_mouse.y)) 
	{
		canvas->mouseButtonDown(event, pos_mouse);
	}
}

void Viewport::mouseButtonUp(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	
	if (v_scroll->on_focus() && v_scroll->is_show() && h_scroll->is_show())
	{
		v_scroll->mouseButtonUp(event);
		return;
	}

	if (h_scroll->on_focus() && v_scroll->is_show() && h_scroll->is_show())
	{
		h_scroll->mouseButtonUp(event);
		return;
	}

	if (canvas->on_hover(pos_mouse.x, pos_mouse.y)) 
	{
		canvas->mouseButtonUp(event, pos_mouse);
	}
}

void Viewport::mouseMotion(SDL_Event* event)
{

	//cout << event->motion.x << "  " << event->motion.y << endl;
	//cout << "relative x and y " << event->motion.xrel << "  " << event->motion.yrel << endl;

	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	
	if (v_scroll->on_focus() && v_scroll->is_show() && h_scroll->is_show())
	{
		v_scroll->mouseMotion(event);

		double procent = v_scroll->get_value();
		int new_y = this->height / 2 - canvas->get_height() / 2 - procent * canvas->get_height();
		canvas->set_position(canvas->get_x(), new_y);


		clear();
		canvas->update();
		update();

		return;
	}

	if (h_scroll->on_focus() && v_scroll->is_show() && h_scroll->is_show())
	{
		h_scroll->mouseMotion(event);

		double procent = h_scroll->get_value();
		int new_x = this->width / 2 - canvas->get_width() / 2 - procent * canvas->get_width();
		canvas->set_position(new_x, canvas->get_y());

		clear();
		canvas->update();
		update();

		return;
	}


	if (canvas->on_hover(pos_mouse.x, pos_mouse.y)) 
	{
		canvas->mouseMotion(event, pos_mouse);
	}

	
}

void Viewport::mouseWheel(SDL_Event* event)
{
	
	
	if (SDL_GetModState() & KMOD_ALT)
	{

		if (event->wheel.y > 0)
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
		else if (event->wheel.y < 0)
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

		SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
		update_coord(&pos_mouse.x, &pos_mouse.y);
		this->set_canvas_size_factor(size_factor, event->wheel.y < 0 ? -1 : 1);



		// update scale in info
		scale_info->set_scale(size_factor);

		// update vertical scroll slider position
		int new_y = canvas->get_y();
		double procents = ((this->height / 2. - canvas->get_height() / 2.) - new_y) / (double)canvas->get_height();
		v_scroll->set_value(procents);
		v_scroll->update();

		// update horizontal scroll slider position
		int new_x = canvas->get_x();
		double x_procent = ((this->width / 2. - canvas->get_width() / 2.) - new_x) / (double)canvas->get_width();
		h_scroll->set_value(x_procent);
		h_scroll->update();


		if (canvas->get_width() >= this->width || canvas->get_height() >= this->height)
		{
			v_scroll->show();
			h_scroll->show();

			v_scroll->set_step(1000 / size_factor);
			v_scroll->update();

			h_scroll->set_step(1000 / size_factor);
			h_scroll->update();
		}
		else
		{
			v_scroll->hide();
			h_scroll->hide();
		}

		update();
	}
	else if (SDL_GetModState() & KMOD_CTRL && v_scroll->is_show() && h_scroll->is_show())
	{
		if (event->wheel.y > 0)
		{
			h_scroll->shift(-10);
		}
		else if (event->wheel.y < 0)
		{
			h_scroll->shift(10);
		}

		double procent = h_scroll->get_value();
		int new_x = this->width / 2. - canvas->get_width() / 2. - procent * canvas->get_width();
		canvas->set_position(new_x, canvas->get_y());
		clear();
		canvas->update();
		update();
	}
	else if (v_scroll->is_show() && h_scroll->is_show())
	{
		if (event->wheel.y > 0)
		{
			v_scroll->shift(-10);
		}
		else if (event->wheel.y < 0)
		{
			v_scroll->shift(10);
		}

		double procent = v_scroll->get_value();
		int new_y = this->height / 2. - canvas->get_height() / 2. - procent * canvas->get_height();
		canvas->set_position(canvas->get_x(), new_y);
		clear();
		canvas->update();
		update();
	}
	
}

void Viewport::keyDown(SDL_Event* event)
{
}

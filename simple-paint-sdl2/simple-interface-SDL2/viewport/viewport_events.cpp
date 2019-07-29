#include "viewport.h"

void Viewport::mouseButtonDown(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


	if (v_scroll->slider_hover(pos_mouse.x, pos_mouse.y))
	{
		v_scroll->mouseButtonDown(event);
		return;
	}

	
	if (v_scroll->body_hover(pos_mouse.x, pos_mouse.y))
	{
		v_scroll->mouseButtonDown(event);

		double procent = v_scroll->get_value();
		int dy = 1000 * procent;
		cout << "shift " << dy << endl;

		int canvas_width;
		int canvas_factor = canvas->get_size_factor();

		canvas->get_size(&canvas_width, NULL);
		canvas->set_position(width / 2 - canvas_width * canvas_factor / 2, dy);

		clear();
		canvas->update();
		update();
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

	push_v_scroll = v_scroll->on_focus();
	if (push_v_scroll)
	{
		v_scroll->mouseButtonUp(event);
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

	
	if (v_scroll->on_focus())
	{
		v_scroll->mouseMotion(event);

		double procent = v_scroll->get_value();


		int new_y = this->height / 2 - canvas->get_height() / 2 + procent * canvas->get_height();

		cout << "shift " << new_y << endl;

		canvas->set_position(width / 2 - canvas->get_width() / 2, new_y);




		clear();
		canvas->update();
		update();

		return;
	}


	if (canvas->on_hover(pos_mouse.x, pos_mouse.y)) {
		canvas->mouseMotion(event, pos_mouse);
	}

	
}

void Viewport::mouseWheel(SDL_Event* event)
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


	int new_ys = canvas->get_y();
	double procents = (new_ys - (this->height / 2. - canvas->get_height() / 2.)) / (double)canvas->get_height();

	cout << "procent equal " << procents << endl;

	v_scroll->set_value(procents);
	v_scroll->update();
	update();

	if (size_factor > 1)
	{
		v_scroll->set_step(1000 / size_factor);
		v_scroll->update();
		update();
	}
}

void Viewport::keyDown(SDL_Event* event)
{
}

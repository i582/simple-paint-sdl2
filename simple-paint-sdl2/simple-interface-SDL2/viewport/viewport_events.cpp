#include "viewport.h"

void Viewport::mouseButtonDown(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	if (v_scroll->v_scroll_hover(pos_mouse.x, pos_mouse.y)) 
	{
		v_scroll->mouseButtonDown(event);
		return;
	}

	if (canvas->on_hover(pos_mouse.x, pos_mouse.y)) {
		canvas->mouseButtonDown(event, pos_mouse);
	}
}

void Viewport::mouseButtonUp(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	if (v_scroll->v_scroll_hover(pos_mouse.x, pos_mouse.y))
	{
		v_scroll->mouseButtonUp(event);
		return;
	}

	if (canvas->on_hover(pos_mouse.x, pos_mouse.y)) {
		canvas->mouseButtonUp(event, pos_mouse);
	}
}

void Viewport::mouseMotion(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


	if (v_scroll->v_scroll_hover(pos_mouse.x, pos_mouse.y))
	{
		v_scroll->mouseMotion(event);
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

}

void Viewport::keyDown(SDL_Event* event)
{
}

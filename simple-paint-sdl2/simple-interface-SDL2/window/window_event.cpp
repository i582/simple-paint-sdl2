#include "window.h"

void Window::mouseButtonDown(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (event->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::mouseButtonUp(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (event->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::mouseMotion(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (event->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::mouseWheel(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (event->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::keyDown(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (event->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::keyUp(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (event->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

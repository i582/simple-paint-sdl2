#include "window.h"

void Window::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (e->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (e->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (e->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::mouseWheel(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (e->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::keyDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (e->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

void Window::keyUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	switch (e->window.windowID)
	{
	case 1: {
		// code
		break;
	}

	default:break;
	}
}

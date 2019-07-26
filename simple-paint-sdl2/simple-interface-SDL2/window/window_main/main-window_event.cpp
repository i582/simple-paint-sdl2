#include "main-window.h"

void MainWindow::mouseButtonDown(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonDown(event);
	}
}

void MainWindow::mouseButtonUp(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonUp(event);
	}
}

void MainWindow::mouseMotion(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) 
	{
		viewport->mouseMotion(event);
	}
}

void MainWindow::mouseWheel(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseWheel(event);
	}
}

void MainWindow::keyDown(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->keyDown(event);
	}
}

void MainWindow::keyUp(SDL_Event* event)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	// code
}

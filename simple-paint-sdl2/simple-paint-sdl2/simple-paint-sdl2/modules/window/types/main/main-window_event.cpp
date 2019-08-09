#include "main-window.h"

void MainWindow::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonDown(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseButtonDown(e);
	}
	
}

void MainWindow::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonUp(e);
	}

	if (toolbar->on_hover(mouse_coord.x, mouse_coord.y))
	{
		toolbar->mouseButtonUp(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseButtonUp(e);
	}
	
}

void MainWindow::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) 
	{
		viewport->mouseMotion(e);
	}

	if (toolbar->on_hover(mouse_coord.x, mouse_coord.y))
	{
		toolbar->mouseMotion(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseMotion(e);
	}
}

void MainWindow::mouseWheel(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseWheel(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseWheel(e);
	}
}

void MainWindow::keyDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
}

void MainWindow::keyUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	// code
}

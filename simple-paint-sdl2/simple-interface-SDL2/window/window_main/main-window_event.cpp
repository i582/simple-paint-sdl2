#include "main-window.h"

void MainWindow::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonDown(e);
	}


	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseButtonDown(e);
	}
}

void MainWindow::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	for (auto& tool : tools)
	{
		if (tool->on_hover(mouse_coord.x, mouse_coord.y))
		{
			tool->set_selected(true);
		}
		else
		{
			tool->set_selected(false);
		}
	}

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonUp(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseButtonUp(e);
	}
}

void MainWindow::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	for (auto& tool : tools)
	{
		if (tool->on_hover(mouse_coord.x, mouse_coord.y))
			tool->set_hover(true);
		else
			tool->set_hover(false);
	}

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) 
	{
		viewport->mouseMotion(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseMotion(e);
	}
}

void MainWindow::mouseWheel(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseWheel(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseMotion(e);
	}
}

void MainWindow::keyDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->keyDown(e);
	}
}

void MainWindow::keyUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	// code
}

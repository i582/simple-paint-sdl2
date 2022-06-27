#include "main-window.h"

void MainWindow::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonDown(e);
	}

	if (toolbar->on_hover(mouse_coord.x, mouse_coord.y))
	{
		toolbar->mouseButtonDown(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseButtonDown(e);
	}

	if (focus_element != nullptr)
	{
		focus_element->do_update();
		focus_element->mouseButtonDown(e);

		update();

		if (!focus_element->is_focus())
		{
			focus_element = nullptr;
		}
		else
		{	
			return;
		}
	}

	for (auto& control : controls)
	{
		if (control->on_hover(mouse_coord.x, mouse_coord.y))
		{
			focus_element = control->focus();
			focus_element->do_update()->mouseButtonDown(e);
			update();
			return;
		}
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


	if (focus_element != nullptr)
	{
		focus_element->do_update()->mouseButtonUp(e);
		update();
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

	for (auto& control : controls)
	{
		if (control->on_hover(mouse_coord.x, mouse_coord.y))
		{
			control->mouseMotion(e);
//			update();
			return;
		}
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

void MainWindow::textInput(SDL_Event* e)
{
	if (focus_element != nullptr)
	{
		focus_element->do_update()->textInput(e);
		update();
	}
}

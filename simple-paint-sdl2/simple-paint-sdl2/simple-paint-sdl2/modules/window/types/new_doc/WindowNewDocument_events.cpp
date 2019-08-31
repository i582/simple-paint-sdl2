#include "WindowNewDocument.h"


void NewDocumentWindow::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (focus_element != nullptr)
	{
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
			focus_element->mouseButtonDown(e);
			update();
			return;
		}
	}
}

void NewDocumentWindow::mouseButtonUp(SDL_Event* e)
{
	if (focus_element != nullptr)
	{
		focus_element->do_update()->mouseButtonUp(e);
		update();
	}
}

void NewDocumentWindow::mouseMotion(SDL_Event* e)
{
}

void NewDocumentWindow::mouseWheel(SDL_Event* e)
{
}

void NewDocumentWindow::keyDown(SDL_Event* e)
{
	if (focus_element != nullptr)
	{
		focus_element->keyDown(e);
		update();
	}
}

void NewDocumentWindow::keyUp(SDL_Event* e)
{
	if (focus_element != nullptr)
	{
		focus_element->keyUp(e);
		update();
	}
}

void NewDocumentWindow::textInput(SDL_Event* e)
{
	if (focus_element != nullptr)
	{
		focus_element->textInput(e);
		update();
	}
}

#include "menubar.h"

MenuBar::MenuBar(Window* parent_window, SDL_Rect size, int object_ID)
	: Control(parent_window->getRenderer(), NULL, size, "", object_ID)
{
	this->parent_window = parent_window;
	init();

}

void MenuBar::init()
{

	menu_elements.push_back(new DropDownList(parent_window, texture, "Open", 100, { 0, 7, 50, 20 }));
	menu_elements.push_back(new DropDownList(parent_window, texture, "Window", 100, { 50, 7, 60, 20 }));
	menu_elements.push_back(new DropDownList(parent_window, texture, "Info", 100, { 110, 7, 50, 20 }));
}

void MenuBar::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, Colors::element_d_background.r, Colors::element_d_background.g, Colors::element_d_background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);


	for (auto& item : menu_elements)
	{
		item->update();
	}



	SDL_SetRenderTarget(renderer, NULL);


	SDL_RenderCopy(renderer, texture, NULL, &size);
}

void MenuBar::mouseButtonDown(SDL_Event* e)
{
	is_updated = false;

	SDL_GetMouseState(&mouse_p.x, &mouse_p.y);
	//update_coord(&mouse_p.x, &mouse_p.x);

	for (auto& item : menu_elements)
	{
		if (item->on_hover(mouse_p.x, mouse_p.y))
		{
			item->mouseButtonDown(e);
			update();
			return;
		}
	}
}

void MenuBar::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_p.x, &mouse_p.y);
	//update_coord(&mouse_p.x, &mouse_p.x);

	for (auto& item : menu_elements)
	{
		if (item->on_hover(mouse_p.x, mouse_p.y))
		{
			item->mouseButtonUp(e);
			update();
			return;
		}
	}
}

void MenuBar::mouseMotion(SDL_Event* e)
{
}

void MenuBar::keyDown(SDL_Event* e)
{
}

void MenuBar::keyUp(SDL_Event* e)
{
}

void MenuBar::textInput(SDL_Event* e)
{
}

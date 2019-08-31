#include "DropDown.h"
#include "../window/types/main/main-window.h"

DropDownList::DropDownList(Window* parent, SDL_Texture* parent_target, string text, int control_ID, SDL_Rect size)
	: Control(parent->getRenderer(), parent_target, size, text, control_ID)
{
	this->parent = parent;
	this->opened = false;

	setup();
}

void DropDownList::setup()
{

	
	
	
	
}

void DropDownList::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	if (blocked)
		SDL_SetRenderDrawColor(renderer, Colors::element_blocked.r, Colors::element_blocked.g, Colors::element_blocked.b, 0xFF);
	else
		if (click)
			SDL_SetRenderDrawColor(renderer, Colors::drop_down_back.r, Colors::drop_down_back.g, Colors::drop_down_back.b, 0xFF);
		else
			if (opened)
				SDL_SetRenderDrawColor(renderer, Colors::drop_down_back.r, Colors::drop_down_back.g, Colors::drop_down_back.b, 0xFF);
			else
				SDL_SetRenderDrawColor(renderer, Colors::background.r, Colors::background.g, Colors::background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);

	render_text(text, { 0, 0, size.w, size.h }, CENTER_ALIGN);
}

void DropDownList::mouseButtonDown(SDL_Event* e)
{
	is_updated = false;
	click = true;
	 
	if (opened)
	{
		//MainWindow::drop_window->hide();
		//opened = false;
	}
	else
	{
		//MainWindow::drop_window->set_position(size.x + parent->x, size.y + size.h + parent->y);
		//MainWindow::drop_window->show();
		//MainWindow::drop_window->render();
		//opened = true;
	}

	check_click_out();
}

void DropDownList::mouseButtonUp(SDL_Event* e)
{
	is_updated = false;
	click = false;
}

void DropDownList::mouseMotion(SDL_Event* e)
{
}

void DropDownList::keyDown(SDL_Event* e)
{
}

void DropDownList::keyUp(SDL_Event* e)
{
}

void DropDownList::textInput(SDL_Event* e)
{
}

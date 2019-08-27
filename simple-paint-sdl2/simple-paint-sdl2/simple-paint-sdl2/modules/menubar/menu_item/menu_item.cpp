#include "menu_item.h"

MenuItem::MenuItem(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, string text, int object_ID)
	: Control(renderer, parent_target, size, text, object_ID)
{



}

void MenuItem::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	if (blocked)
		SDL_SetRenderDrawColor(renderer, Colors::element_blocked.r, Colors::element_blocked.g, Colors::element_blocked.b, 0xFF);
	else
		if (click)
			SDL_SetRenderDrawColor(renderer, Colors::element_background_click.r, Colors::element_background_click.g, Colors::element_background_click.b, 0xFF);
		else
			SDL_SetRenderDrawColor(renderer, Colors::element_background.r, Colors::element_background.g, Colors::element_background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);
 

	render_text(text, { 0, 0, size.w, size.h }, CENTER_ALIGN);

	SDL_SetRenderTarget(renderer, NULL);
}

void MenuItem::mouseButtonDown(SDL_Event* e)
{
}

void MenuItem::mouseButtonUp(SDL_Event* e)
{
}

void MenuItem::mouseMotion(SDL_Event* e)
{
}

void MenuItem::keyDown(SDL_Event* e)
{
}

void MenuItem::keyUp(SDL_Event* e)
{
}

void MenuItem::textInput(SDL_Event* e)
{
}

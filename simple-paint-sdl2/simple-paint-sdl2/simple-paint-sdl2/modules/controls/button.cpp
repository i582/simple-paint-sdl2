#include "button.h"
#include "../editor/editor.h"



Button::Button(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size)
	: Control(parent->getRenderer(), parent_target, size, text, control_ID)
{

}


Uint32 Button::animate(Uint32 interval, void* param)
{
	((Button*)param)->click = interval % 20;
	cout << interval << endl;
	((Button*)param)->update();
	return interval != 2000;
}

void Button::update_()
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


	if (click && !blocked || focused)
		SDL_SetRenderDrawColor(renderer, Colors::element_border_click.r, Colors::element_border_click.g, Colors::element_border_click.b, 0xFF);
	else
		SDL_SetRenderDrawColor(renderer, Colors::element_border.r, Colors::element_border.g, Colors::element_border.b, 0xFF);
	SDL_RenderDrawRect(renderer, NULL);


	render_text(text, { 0, 0, size.w, size.h }, CENTER_ALIGN);
}

void Button::mouseButtonDown(SDL_Event* e)
{
	is_updated = false;
	click = true;

	Editor::push_event(new Event(BUTTON, BUTTON_PRESSED, control_ID));

	check_click_out();
}

void Button::mouseButtonUp(SDL_Event* e)
{
	is_updated = false;
	click = false;

	Editor::push_event(new Event(BUTTON, BUTTON_RELEASED, control_ID));
}

void Button::mouseMotion(SDL_Event* e)
{
	is_updated = false;
	hovered = true;
}

void Button::keyDown(SDL_Event* e)
{
}

void Button::keyUp(SDL_Event* e)
{
}

void Button::textInput(SDL_Event* e)
{
}

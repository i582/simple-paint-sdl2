#include "Input.h"

Input::Input(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size, TTF_Font* font)
	: Control(parent->getRenderer(), parent_target, size, text, control_ID)
{
	this->font = font;
}

void Input::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	if (blocked)
		SDL_SetRenderDrawColor(renderer, Colors::element_blocked.r, Colors::element_blocked.g, Colors::element_blocked.b, 0xFF);
	else
		SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
	SDL_RenderFillRect(renderer, NULL);


	render_text(text, { 0, 0, size.w, size.h }, LEFT_ALIGN, font);

	SDL_SetRenderTarget(renderer, texture);

	Primitives::renderer = renderer;

	if (focused && !blocked)
		Primitives::color = &Colors::element_border_click;
	else
		Primitives::color = &Colors::element_border;

	Primitives::rounded_rect({ 0, 0, size.w, size.h }, 5);

}

void Input::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_p.x, &mouse_p.y);
	is_updated = false; 
	focused = on_hover(mouse_p.x, mouse_p.y);
}

void Input::mouseButtonUp(SDL_Event* e)
{
	is_updated = false;
}

void Input::mouseMotion(SDL_Event* e)
{
}

void Input::keyDown(SDL_Event* e)
{
	is_updated = false;

	if (e->key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
	{
		text.pop_back();
		render_text_(text, { 0, 0, size.w, size.h }, LEFT_ALIGN, font);
	}
	else if (e->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
	{
		SDL_SetClipboardText(text.c_str());
	}
	else if (e->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
	{
		text = SDL_GetClipboardText();
		render_text_(text, { 0, 0, size.w, size.h }, LEFT_ALIGN, font);
	}
}

void Input::keyUp(SDL_Event* e)
{

}

void Input::textInput(SDL_Event* e)
{
	is_updated = false; 

	if (!((e->text.text[0] == 'c' || e->text.text[0] == 'C') && (e->text.text[0] == 'v' || e->text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL))
		text += e->text.text;

	render_text_(text, { 0, 0, size.w, size.h }, LEFT_ALIGN, font);
}

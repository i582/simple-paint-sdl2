#include "Label.h"

Label::Label(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size, TTF_Font* font)
	: Control(parent->getRenderer(), parent_target, size, text, control_ID)
{
	this->font = font;
	this->need_update = false;
}

void Label::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
	SDL_RenderFillRect(renderer, NULL);

	render_text(text, { 0, 0, size.w, size.h }, LEFT_NO_PAD_ALIGN, font);

	SDL_SetRenderTarget(renderer, NULL);

	focused = false;
}

void Label::mouseButtonDown(SDL_Event* e)
{
}

void Label::mouseButtonUp(SDL_Event* e)
{
}

void Label::mouseMotion(SDL_Event* e)
{
}

void Label::keyDown(SDL_Event* e)
{
}

void Label::keyUp(SDL_Event* e)
{
}

void Label::textInput(SDL_Event* e)
{
}

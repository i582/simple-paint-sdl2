#include "RadioButton.h"
#include "../editor/editor.h"

RadioButton::RadioButton(Window* parent, SDL_Texture* parent_target, int group_ID, int control_ID, SDL_Rect size, int style, bool checked)
	: Checkbox(parent->getRenderer(), parent_target, control_ID, size, style, checked)
{
	this->group_ID = group_ID;
}

void RadioButton::setup()
{
	switch (style)
	{
	case SIMPLE:
	{
		border = false;
		image_select = IMG_LoadTexture(renderer, "././resources/images/radiobutton/select.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/radiobutton/unselect.png");

		break;
	}

	default:
		throw logic_error("Invalid style argument");
		break;
	}


	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
}

void RadioButton::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, Colors::element_background.r, Colors::element_background.g, Colors::element_background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);

	if (checked)
	{
		int select_width, select_height;
		SDL_QueryTexture(image_select, nullptr, nullptr, &select_width, &select_height);
		SDL_Rect r = { (int)(size.w / 2. - select_width / 2.), (int)(size.h / 2. - select_height / 2.), select_width, select_height };
		SDL_RenderCopy(renderer, image_select, NULL, &r);
	}
	else
	{
		int unselect_width, unselect_height;
		SDL_QueryTexture(image_unselect, nullptr, nullptr, &unselect_width, &unselect_height);
		SDL_Rect r = { (int)(size.w / 2. - unselect_width / 2.), (int)(size.h / 2. - unselect_height / 2.), unselect_width, unselect_height };
		SDL_RenderCopy(renderer, image_unselect, NULL, &r);
	}

	if (border)
	{
		SDL_SetRenderDrawColor(renderer, Colors::viewport_border.r, Colors::viewport_border.g, Colors::viewport_border.b, 0xFF);
		SDL_RenderDrawRect(renderer, NULL);
	}

	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, parent_target);
}

void RadioButton::mouseButtonDown(SDL_Event* e)
{
	check_click_out();
}

void RadioButton::mouseButtonUp(SDL_Event* e)
{
	is_updated = false;

	if (checked)
	{
		Editor::push_event(new Event(RADIOBUTTON, RADIOBUTTON_UNCHECKED, control_ID));
	}
	else
	{
		Editor::push_event(new Event(RADIOBUTTON, RADIOBUTTON_CHECKED, control_ID));
	}

	checked = !checked;
}

void RadioButton::mouseMotion(SDL_Event* e)
{
}

void RadioButton::keyDown(SDL_Event* e)
{
}

void RadioButton::keyUp(SDL_Event* e)
{
}

void RadioButton::textInput(SDL_Event* e)
{
}

#include "Checkbox.h"
#include "../editor/editor.h"

Checkbox::Checkbox(SDL_Renderer* renderer, SDL_Texture* parent_target, int control_ID, SDL_Rect size, int style, bool checked) :
	Control(renderer, parent_target, size, "", control_ID)
{
	IMG_Init(IMG_INIT_PNG);

	this->style = style;
	this->checked = checked;
	this->border = true;

	init();
}

Checkbox::~Checkbox()
{
	SDL_DestroyTexture(image_select);
	SDL_DestroyTexture(image_unselect);
}

void Checkbox::init()
{
	setup();
}

void Checkbox::setup()
{
	switch (style)
	{
	case SIMPLE:
	{
		border = false;
		image_select = IMG_LoadTexture(renderer, "././resources/images/checkbox/select_1.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/checkbox/unselect_1.png");

		break;
	}

	case EYE:
	{
		border = true;
		image_select = IMG_LoadTexture(renderer, "././resources/images/checkbox/select_eye.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/checkbox/unselect_eye.png");

		break;
	}

	case BLOCK:
	{
		border = true;
		image_select = IMG_LoadTexture(renderer, "././resources/images/checkbox/blocked.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/checkbox/unselect_eye.png");

		break;
	}

	default:
		
		break;
	}


	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	//SDL_SetTextureAlphaMod(texture, 0x00);
}

void Checkbox::update_()
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

void Checkbox::mouseButtonDown(SDL_Event* e)
{
	check_click_out();
}

void Checkbox::mouseButtonUp(SDL_Event* e)
{
	is_updated = false;

	if (checked)
	{
		Editor::push_event(new Event(CHECKBOX, CHECKBOX_UNCHECKED, control_ID));
	}
	else
	{
		Editor::push_event(new Event(CHECKBOX, CHECKBOX_CHECKED, control_ID));
	}

	checked = !checked;
}

void Checkbox::mouseMotion(SDL_Event* e)
{
}

void Checkbox::keyDown(SDL_Event* e)
{
}

void Checkbox::keyUp(SDL_Event* e)
{
}

void Checkbox::textInput(SDL_Event* e)
{
}
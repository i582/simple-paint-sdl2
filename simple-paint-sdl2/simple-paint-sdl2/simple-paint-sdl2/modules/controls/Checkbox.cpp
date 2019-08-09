#include "Checkbox.h"

Checkbox::Checkbox(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, int style, bool checked, string text, string font, int font_size) :
	_Control(renderer, size, text, font, font_size)
{
	IMG_Init(IMG_INIT_PNG);
	this->parent_target = parent_target;
	this->style = style;
	this->checked = checked;
	this->border = true;
	setup();
}

Checkbox::~Checkbox()
{
	SDL_DestroyTexture(image_select);
	SDL_DestroyTexture(image_unselect);
}

void Checkbox::setup()
{
	switch (style)
	{
	case SIMPLE:
	{
		if (size.w == -1 && size.h == -1)
		{
			size.w = 25;
			size.h = 25;
		}

		border = true;
		image_select = IMG_LoadTexture(renderer, "././resources/images/checkbox/select_1.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/checkbox/unselect_1.png");

		break;
	}

	case EYE:
	{
		if (size.w == -1 && size.h == -1)
		{
			size.w = 25;
			size.h = 25;
		}

		border = true;
		image_select = IMG_LoadTexture(renderer, "././resources/images/checkbox/select_eye.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/checkbox/unselect_eye.png");

		break;
	}

	case BLOCK:
	{
		if (size.w == -1 && size.h == -1)
		{
			size.w = 25;
			size.h = 25;
		}

		border = true;
		image_select = IMG_LoadTexture(renderer, "././resources/images/checkbox/blocked.png");
		image_unselect = IMG_LoadTexture(renderer, "././resources/images/checkbox/unselect_eye.png");

		break;
	}

	default:
		throw logic_error("Invalid style argument");
		break;
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	//SDL_SetTextureAlphaMod(texture, 0x00);
}

void Checkbox::update()
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

	SDL_RenderCopy(renderer, texture, NULL, &size);
	SDL_RenderPresent(renderer);
}

void Checkbox::mouseButtonDown(SDL_Event* e)
{

}

void Checkbox::mouseButtonUp(SDL_Event* e)
{
	checked = !checked;
}

void Checkbox::mouseMotion(SDL_Event* e)
{
}

void Checkbox::check()
{
	checked = true;
}

void Checkbox::uncheck()
{
	checked = false;
}

bool Checkbox::is_checked()
{
	return checked;
}

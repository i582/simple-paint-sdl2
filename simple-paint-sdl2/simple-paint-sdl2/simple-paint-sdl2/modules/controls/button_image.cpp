#include "button_image.h"

ButtonImg::ButtonImg(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size, string path)
	: Button(parent, parent_target, control_ID, text, size)
{
	img_texture = IMG_LoadTexture(renderer, path.c_str());
}

ButtonImg::~ButtonImg()
{
	SDL_DestroyTexture(img_texture);
}

void ButtonImg::init()
{
	
}

void ButtonImg::update_()
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
			SDL_SetRenderDrawColor(renderer, Colors::background.r, Colors::background.g, Colors::background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);



	int select_width, select_height;
	SDL_QueryTexture(img_texture, nullptr, nullptr, &select_width, &select_height);
	SDL_Rect r = { (int)(size.w / 2. - select_width / 2.), (int)(size.h / 2. - select_height / 2.), select_width, select_height };
	SDL_RenderCopy(renderer, img_texture, NULL, &r);



	SDL_SetRenderTarget(renderer, parent_target);

	SDL_RenderCopy(renderer, texture, NULL, &size);
	SDL_RenderPresent(renderer);

}

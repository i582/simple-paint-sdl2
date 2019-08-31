#include "button_image.h"

ButtonImg::ButtonImg(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size, SDL_Surface* image)
	: Button(parent, parent_target, control_ID, text, size)
{
	img_texture = SDL_CreateTextureFromSurface(renderer, image);
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

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
	SDL_RenderClear(renderer);

	if (blocked)
		SDL_SetRenderDrawColor(renderer, Colors::element_blocked.r, Colors::element_blocked.g, Colors::element_blocked.b, 0xFF);
	else
		if (click)
			SDL_SetRenderDrawColor(renderer, Colors::element_background_click.r, Colors::element_background_click.g, Colors::element_background_click.b, 0xFF);
		else
			SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
	SDL_RenderFillRect(renderer, NULL);



	int select_width, select_height;
	SDL_QueryTexture(img_texture, nullptr, nullptr, &select_width, &select_height);
	SDL_Rect r = { (int)(size.w / 2. - select_width / 2.), (int)(size.h / 2. - select_height / 2.), select_width, select_height };
	SDL_RenderCopy(renderer, img_texture, NULL, &r);

}

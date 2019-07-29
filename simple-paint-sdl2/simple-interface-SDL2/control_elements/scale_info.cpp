#include "scale_info.h"

ScaleInfo::ScaleInfo(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, double scale, string font, int font_size)
{
	TTF_Init();

	this->parent_target = parent_target;
	this->renderer = renderer;
	this->size = size;
	this->scale = scale;
	this->font = TTF_OpenFont(font.c_str(), font_size);
	
}

ScaleInfo::~ScaleInfo()
{
	TTF_CloseFont(font);
}

void ScaleInfo::update()
{
	SDL_SetRenderTarget(renderer, parent_target);

	SDL_SetRenderDrawColor(renderer, Colors::viewport_border.r, Colors::viewport_border.g, Colors::viewport_border.b, 0xFF);
	SDL_RenderFillRect(renderer, &size);

	
	string str = to_string(scale * 100).substr(0, scale < 10 ? 5 : 6) + '%';

	SDL_Texture* textTexture = nullptr;
	SDL_Surface* textSurface = nullptr;
	SDL_Rect text_rect;

	textSurface = TTF_RenderUTF8_Blended(font, str.c_str(), Colors::element_text);
	if (textSurface == nullptr)
		return;

	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;
	text_rect.x = size.x + 5;
	text_rect.y = size.y + (size.h - textSurface->h) / 2.;

	

	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, textTexture, NULL, &text_rect);
	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}

void ScaleInfo::set_scale(double scale)
{
	this->scale = scale;
	update();
}

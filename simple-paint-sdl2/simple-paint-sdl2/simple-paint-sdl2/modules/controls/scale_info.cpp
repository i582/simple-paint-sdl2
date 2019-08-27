#include "scale_info.h"
#include "../viewport/viewport.h"

ScaleInfo::ScaleInfo(SDL_Renderer* renderer, Viewport* parent, SDL_Rect size, double scale, string font, int font_size)
{
	TTF_Init();

	this->parent = parent;
	this->renderer = renderer;
	this->size = size;
	this->scale = scale;
	this->font = TTF_OpenFont(font.c_str(), font_size);
	
	this->texture = nullptr;
	this->text_texture = nullptr;

	this->is_updated = false;

	init();
}

ScaleInfo::~ScaleInfo()
{
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(text_texture);
}

void ScaleInfo::init()
{
	this->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);
}

void ScaleInfo::update_()
{
	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, Colors::viewport_border.r, Colors::viewport_border.g, Colors::viewport_border.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);

	string str = to_string(scale * 100).substr(0, scale < 10 ? 5 : 6) + '%';
	SDL_Rect text_rect;

	SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, str.c_str(), Colors::element_text);

	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;
	text_rect.x = 5;
	text_rect.y = (size.h - textSurface->h) / 2;


	text_texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
	SDL_RenderPresent(renderer);

	SDL_FreeSurface(textSurface);
	SDL_SetRenderTarget(renderer, NULL);
}

void ScaleInfo::update()
{
	if (is_updated == false)
	{
		update_();
		is_updated = true;
	}

	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_RenderCopy(renderer, texture, NULL, &size);
	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void ScaleInfo::set_scale(double scale)
{
	this->scale = scale;
	this->is_updated = false;
	update();
}

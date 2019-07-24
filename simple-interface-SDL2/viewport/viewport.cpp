#include "viewport.h"

Viewport::Viewport(SDL_Renderer* renderer, int width, int height, int x, int y)
{
	this->renderer = renderer;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;

	texture = nullptr;
	canvas = nullptr;

	size_factor = 1.0;
}

Viewport::~Viewport()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Viewport::init()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	canvas = IMG_LoadTexture(renderer, "sfx/4.png");

	int image_width;
	int image_height;
	SDL_QueryTexture(image, NULL, NULL, &image_width, &image_height);

	SDL_Rect render_rect = { 100, 100, image_width, image_height };

	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, image, NULL, &render_rect);
	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, NULL);
}

void Viewport::update()
{
	SDL_Rect copy_rect = { x, y, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &copy_rect);
	SDL_RenderPresent(renderer);
}

bool Viewport::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { this->x, this->y, width, height };
	return SDL_PointInRect(&p, &r);
}

void Viewport::update_coord(int* x, int* y)
{
	*x -= this->x;
	*y -= this->y;
}

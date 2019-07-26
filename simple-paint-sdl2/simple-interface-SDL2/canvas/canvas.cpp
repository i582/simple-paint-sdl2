#include "canvas.h"

Canvas::Canvas(SDL_Renderer* renderer, SDL_Texture* parentTarget, int x, int y, int width, int height)
{
	this->renderer = renderer;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;

	this->texture = nullptr;

	this->size_factor = 1.0;

	this->parentTarget = parentTarget;

	init();
}

Canvas::~Canvas()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Canvas::init()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	SDL_SetRenderTarget(renderer, texture);

	SDL_Texture* image = IMG_LoadTexture(renderer, "sfx/4.png");
	SDL_Rect image_rect = {0, 0, width, height};
	SDL_RenderCopy(renderer, image, NULL, &image_rect);
	
	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

void Canvas::update()
{
	SDL_SetRenderTarget(renderer, parentTarget);

	SDL_Rect copy_rect = { x, y, width * size_factor, height * size_factor };
	SDL_RenderCopy(renderer, texture, NULL, &copy_rect);
	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);
}

bool Canvas::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { this->x, this->y, width * size_factor, height * size_factor };
	return SDL_PointInRect(&p, &r);
}

void Canvas::set_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Canvas::set_size_factor(double size_factor)
{
	this->size_factor = size_factor;
}

void Canvas::shift_position(int x, int y)
{
	this->x -= x;
	this->y -= y;
}

void Canvas::center_align(int width, int height)
{
	int new_x = width / 2 - this->width * size_factor / 2;
	int new_y = height / 2 - this->height * size_factor / 2;

	set_position(new_x, new_y);
}

bool Canvas::full_in_viewport(int width, int height)
{
	return ((this->width * size_factor) <= width) && ((this->height * size_factor) <= height);
}

void Canvas::get_size(int* width, int* height)
{
	*width = this->width * size_factor;
	*height = this->height * size_factor;
}

void Canvas::get_position(int* x, int* y)
{
	*x = this->x;
	*y = this->y;
}

double Canvas::get_size_factor()
{
	return size_factor;
}

void Canvas::update_coord(int* x, int* y)
{
	*x = (*x - this->x) / size_factor;
	*y = (*y - this->y) / size_factor;
}

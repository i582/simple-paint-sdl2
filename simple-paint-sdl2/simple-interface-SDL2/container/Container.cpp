#include "Container.h"
#include "ContainerVScroll.h"

Container::Container(SDL_Renderer* renderer, SDL_Rect size)
{
	this->renderer = renderer;
	this->size = size;

	setup();
}

void Container::setup()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);

	v_scroll = new ContainerVScroll(renderer, this, { size.w - 16, 0, 16, size.h }, 500, 1000, 100);
}

void Container::update()
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, Colors::element_d_background.r, Colors::element_d_background.g, Colors::element_d_background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);
	SDL_SetRenderTarget(renderer, NULL);

	v_scroll->update();

	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, Colors::element_border.r, Colors::element_border.g, Colors::element_border.b, 0xFF);
	SDL_RenderDrawRect(renderer, NULL);
	SDL_SetRenderTarget(renderer, NULL);

	SDL_RenderCopy(renderer, texture, NULL, &size);

	SDL_RenderPresent(renderer);
}

void Container::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

bool Container::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { this->size.x,this->size.y, this->size.w, this->size.h };
	return SDL_PointInRect(&p, &r);
}

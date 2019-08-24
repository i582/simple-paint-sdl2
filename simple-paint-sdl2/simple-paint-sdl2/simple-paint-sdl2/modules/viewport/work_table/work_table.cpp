#include "work_table.h"
#include "../viewport.h"

WorkTable::WorkTable(Viewport* parent, SDL_Rect size)
{
	this->viewport = parent;
	this->canvas = nullptr;
	this->texture = nullptr;
	this->renderer = parent->renderer;
	this->size = size;
	this->size_factor = 1;

	init();
}

WorkTable::~WorkTable()
{
	SDL_DestroyTexture(texture);
	delete canvas;
}

void WorkTable::init()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);
	canvas = new Canvas(renderer, this, { 0, 0, 1000, 1000 });


	clear();
	centering();
}

void WorkTable::update()
{
	canvas->update();

	SDL_SetRenderTarget(renderer, viewport->texture);

	SDL_Rect copy_rect = size; copy_rect.w *= size_factor; copy_rect.h *= size_factor;

	SDL_RenderCopy(renderer, texture, NULL, &copy_rect);
	SDL_RenderPresent(renderer);
	
	SDL_SetRenderTarget(renderer, NULL);
}

void WorkTable::clear()
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, Colors::element_background_focus.r, Colors::element_background_focus.g, Colors::element_background_focus.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);
	SDL_SetRenderTarget(renderer, NULL);
}

void WorkTable::centering()
{
	size.x = viewport->width   / 2. - size.w * size_factor / 2.;
	size.y = viewport->height / 2. - size.h * size_factor / 2.;
}

void WorkTable::set_position(int x, int y)
{
	size.x = x;
	size.y = y;
}

void WorkTable::set_size_factor(double factor)
{
	this->size_factor = factor;
}

Canvas* WorkTable::get_canvas()
{
	return canvas;
}

double WorkTable::get_size_factor()
{
	return size_factor;
}

int WorkTable::get_width()
{
	return size.w;
}

int WorkTable::get_height()
{
	return size.h;
}

int WorkTable::get_y()
{
	return size.y;
}

int WorkTable::get_x()
{
	return size.x;
}

void WorkTable::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

bool WorkTable::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &size);
}

void WorkTable::mouseButtonDown(SDL_Event* e)
{

}

void WorkTable::mouseButtonUp(SDL_Event* e)
{

}

void WorkTable::mouseMotion(SDL_Event* e)
{

}

void WorkTable::mouseWheel(SDL_Event* e)
{

}

void WorkTable::keyDown(SDL_Event* e)
{

}

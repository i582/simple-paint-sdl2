#include "viewport.h"
#include "../control_elements/scroll.h"

Viewport::Viewport(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	this->renderer = renderer;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;

	texture = nullptr;

	canvas = nullptr;

	size_factor = 1.0;

	init();
}

Viewport::~Viewport()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Viewport::init()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	
	
	SDL_SetRenderTarget(renderer, texture);

	Primitives::renderer = renderer;
	Primitives::color = &Colors.viewport_back;
	Primitives::fill_rect(NULL);


	SDL_SetRenderTarget(renderer, NULL);

	int v_width = 16;
	int v_height = this->height;

	v_scroll = new Scroll(renderer, v_width, v_height, width - v_width, 0, 500, 1000, 100);
	v_scroll->set_parent(this);
}

void Viewport::update()
{
	render_scrolls();

	SDL_SetRenderTarget(renderer, NULL);

	SDL_Rect copy_rect = { x, y, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &copy_rect);
	SDL_RenderPresent(renderer);
}

void Viewport::clear()
{
	SDL_SetRenderTarget(renderer, texture);

	Primitives::renderer = renderer;
	Primitives::color = &Colors.viewport_back;
	Primitives::fill_rect(NULL);

	SDL_SetRenderTarget(renderer, NULL);
}

void Viewport::render_scrolls()
{
	v_scroll->render();
}

void Viewport::set_canvas(Canvas* new_canvas)
{
	this->canvas = new_canvas;

	canvas->center_align(width, height);

	this->canvas_update();
}

SDL_Texture* Viewport::get_render_target()
{
	return texture;
}

bool Viewport::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { this->x, this->y, width, height };
	return SDL_PointInRect(&p, &r);
}

void Viewport::set_canvas_position(int x, int y)
{
	canvas->set_position(x, y);
	canvas_update();
}

void Viewport::set_canvas_size_factor(double size_factor, int direction)
{
	

	if (canvas->full_in_viewport(width, height)) 
	{
		canvas->set_size_factor(size_factor);
		canvas->center_align(width, height);
	}
	else {
		// todo Сделать увеличение к курсору
		canvas->set_size_factor(size_factor);
		canvas->center_align(width, height);
	}

	canvas_update();
}

void Viewport::canvas_update()
{
	this->clear();
	canvas->update();
	this->update();
}

void Viewport::update_coord(int* x, int* y)
{
	*x -= this->x;
	*y -= this->y;
}

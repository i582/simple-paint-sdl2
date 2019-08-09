#include "viewport.h"
#include "../viewport/scrolls/v_view_scroll.h"
#include "../viewport/scrolls/h_view_scroll.h"
#include "ctime"

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

	SDL_SetRenderDrawColor(renderer, Colors::viewport_back.r, Colors::viewport_back.g, Colors::viewport_back.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);

	SDL_SetRenderTarget(renderer, NULL);


	int v_width = 16;
	int v_height = this->height - 16;
	v_scroll = new V_ViewScroll(renderer, this, { width - v_width, 0, v_width, v_height }, 1000, 3000, 100);


	int h_width = this->width - 16 - 55;
	int h_height = 16;
	h_scroll = new H_ViewScroll(renderer, this, { 55, height - h_height, h_width, h_height }, 1000, 3000, 100);


	SDL_Rect scale_size = {0, this->height - 16, 55, 16};
	scale_info = new ScaleInfo(renderer, texture, scale_size, 1, "././resources/fonts/verdana.ttf", 10);
}

void Viewport::update()
{
	clear();

	canvas->update();

	render_scrolls();
	scale_info->update();

	SDL_SetRenderTarget(renderer, NULL);

	SDL_Rect copy_rect = { x, y, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &copy_rect);

	SDL_SetRenderDrawColor(renderer, Colors::viewport_border.r, Colors::viewport_border.g, Colors::viewport_border.b, 0xFF);
	copy_rect.x -= 1;
	copy_rect.y -= 1;
	copy_rect.w += 2;
	copy_rect.h += 2;

	SDL_RenderDrawRect(renderer, &copy_rect);

	SDL_RenderPresent(renderer);
}

void Viewport::clear()
{
	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, Colors::viewport_back.r, Colors::viewport_back.g, Colors::viewport_back.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);

	SDL_SetRenderTarget(renderer, NULL);
}

void Viewport::setup_scrolls()
{
	v_scroll->set_step((int)(this->canvas->get_width() / size_factor / size_factor));
	h_scroll->set_step((int)(this->canvas->get_height() / size_factor / size_factor));
	v_scroll->update_scroll_pos();
	h_scroll->update_scroll_pos();
}

void Viewport::render_scrolls()
{
	if (!canvas->full_in_viewport())
	{
		v_scroll->show();
		h_scroll->show();
	}
	else
	{
		v_scroll->hide();
		h_scroll->hide();
	}

	v_scroll->update();
	h_scroll->update();
}

void Viewport::set_canvas(Canvas* new_canvas)
{
	this->canvas = new_canvas;

	set_canvas_size_factor(size_factor);
	canvas->center_align();

	setup_scrolls();
}

void Viewport::set_layer_viewer(LayersViewer* layers_viewer)
{
	this->layers_viewer = layers_viewer;
}

SDL_Texture* Viewport::get_render_target()
{
	return texture;
}

SDL_Rect Viewport::get_size()
{
	return {x, y, width, height};
}

bool Viewport::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { this->x, this->y, width, height };
	return SDL_PointInRect(&p, &r);
}

void Viewport::set_canvas_size_factor(double size_factor)
{
	if (canvas->full_in_viewport()) 
	{
		canvas->set_size_factor(size_factor);
		canvas->center_align();
	}
	else
	{	
		canvas->update_coord(&pos_mouse.x, &pos_mouse.y);

		int x_pos = pos_mouse.x;
		int y_pos = pos_mouse.y;

		int x_pos_must = (int)(x_pos / canvas->get_size_factor() * size_factor);
		int y_pos_must = (int)(y_pos / canvas->get_size_factor() * size_factor);

		canvas->set_size_factor(size_factor);

		SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
		update_coord(&pos_mouse.x, &pos_mouse.y);
		canvas->update_coord(&pos_mouse.x, &pos_mouse.y);

		int x_pos_before = pos_mouse.x;
		int y_pos_before = pos_mouse.y;

		int shift_x = x_pos_before - x_pos_must;
		int shift_y = y_pos_before - y_pos_must;

		canvas->shift_position(shift_x, shift_y);
	}

}

void Viewport::update_coord(int* x, int* y)
{
	*x -= this->x;
	*y -= this->y;
}

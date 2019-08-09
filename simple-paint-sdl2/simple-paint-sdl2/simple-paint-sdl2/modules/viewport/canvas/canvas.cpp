#include "canvas.h"
#include "../viewport.h"
#include "ctime"

Canvas::Canvas(SDL_Renderer* renderer, Viewport* parent, int x, int y, int width, int height)
{
	this->renderer = renderer;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;

	this->texture = nullptr;

	this->size_factor = 1.0;

	this->parent = parent;

	init();
}

Canvas::~Canvas()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Canvas::init()
{

	layers = new Layers(renderer, { 0, 0, width, height });


	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	Layer* layer1 = new Layer(texture, "Layer 0", 0xFF);

	layers->add(layer1);
	

	texture = IMG_LoadTexture(renderer, "./././resources/images/first.png");
	Layer* layer2 = new Layer(texture, "Layer 1", 0xA0);
	//layer2->block();
	layers->add(layer2);


	texture = IMG_LoadTexture(renderer, "./././resources/images/first.png");
	Layer* layer3 = new Layer(texture, "Layer 2", 0xFF);
	layers->add(layer3);
	
	texture = IMG_LoadTexture(renderer, "./././resources/images/4.png");
	Layer* layer4 = new Layer(texture, "Layer 3", 0xFF);
	layers->add(layer4);

	SDL_SetRenderTarget(renderer, layer1->texture);

	SDL_Texture* image = IMG_LoadTexture(renderer, "./././resources/images/4.png");
	SDL_Rect image_rect = {0, 0, width, height};
	SDL_RenderCopy(renderer, image, NULL, &image_rect);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(image);

	SDL_SetRenderTarget(renderer, NULL);

	center_align();
}

void Canvas::update()
{
	SDL_Texture* tex = layers->ready_texture();

	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_Rect copy_rect = { x, y, (int)(width * size_factor), (int)(height * size_factor) };
	SDL_RenderCopy(renderer, tex, NULL, &copy_rect);
	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);

	SDL_DestroyTexture(tex);
}

bool Canvas::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	SDL_Rect r = { this->x, this->y, (int)(width * size_factor), (int)(height * size_factor) };
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
	this->x += x;
	this->y += y;
}

void Canvas::center_align()
{
	this->x = (int)(parent->width / 2. - this->width * size_factor / 2.);
	this->y = (int)(parent->height / 2. - this->height * size_factor / 2.);
}

bool Canvas::full_in_viewport()
{
	return ((this->width * size_factor) <= parent->width) && ((this->height * size_factor) <= parent->height);
}

int Canvas::get_width()
{
	return (int)(width * size_factor);
}

int Canvas::get_height()
{
	return (int)(height * size_factor);
}

void Canvas::get_position(int* x, int* y)
{
	*x = this->x;
	*y = this->y;
}

int Canvas::get_y()
{
	return y;
}

int Canvas::get_x()
{
	return x;
}

double Canvas::get_size_factor()
{
	return size_factor;
}

bool Canvas::get_selected()
{
	return is_selected;
}

Layers* Canvas::get_layers()
{
	return layers;
}

void Canvas::update_coord_with_scale(int* x, int* y)
{
	*x = (int)((*x - this->x) / size_factor);
	*y = (int)((*y - this->y) / size_factor);
}

void Canvas::update_coord(int* x, int* y)
{
	*x -= this->x;
	*y -= this->y;
}

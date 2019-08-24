#include "canvas.h"
#include "../work_table/work_table.h"
#include "../viewport.h"
#include "ctime"

Canvas::Canvas(SDL_Renderer* renderer, WorkTable* parent, SDL_Rect size)
{
	this->renderer = renderer;
	this->parent = parent;
	this->texture = nullptr;
	this->size = size;
	this->size.x = (int)((parent->size.w - this->size.w) / 2.);
	this->size.y = (int)((parent->size.h - this->size.h) / 2.);

	init();
}

Canvas::~Canvas()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Canvas::init()
{

	layers = new Layers(renderer, { 0, 0, size.w, size.h });


	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);
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
	SDL_Rect image_rect = {0, 0, size.w, size.h};
	SDL_RenderCopy(renderer, image, NULL, &image_rect);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(image);

	SDL_SetRenderTarget(renderer, NULL);
}

void Canvas::update()
{
	SDL_Texture* tex = layers->ready_texture();

	SDL_SetRenderTarget(renderer, parent->texture);

	SDL_RenderCopy(renderer, tex, NULL, &size);
	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);

	SDL_DestroyTexture(tex);
}

bool Canvas::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &size);
}

bool Canvas::full_in_viewport()
{
	return size.w * parent->get_size_factor() <= parent->viewport->width && size.h * parent->get_size_factor() <= parent->viewport->height;
}

bool Canvas::get_selected()
{
	return is_selected;
}

Layers* Canvas::get_layers()
{
	return layers;
}

void Canvas::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

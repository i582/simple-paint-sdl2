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
	this->layers = nullptr;
	this->size_factor = 0.5;
	this->pos_mouse = { 0, 0 };
	this->parent = parent;

	this->is_selected = false;
	this->selected_id = -1;

	init();
}

Canvas::~Canvas()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Canvas::init()
{
	this->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	this->background = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);


	layers = new Layers(renderer, { 0, 0, width, height });


	SDL_Texture* tex = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/4.png");
	Layer* layer1 = new Layer(tex, 0, "", 0xFF);
	layers->add(layer1);
	
	
	texture = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/first.png");
	Layer* layer2 = new Layer(texture, 1, "", 0xA0);
	layers->add(layer2);


	texture = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/first.png");
	Layer* layer3 = new Layer(texture, 2, "", 0xFF);
	layers->add(layer3);
	
	texture = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/4.png");
	Layer* layer4 = new Layer(texture, 3, "", 0xFF);
	layers->add(layer4);

	
	center_align();
}

void Canvas::update()
{

	SDL_SetRenderTarget(renderer, background);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xFF);
	SDL_RenderFillRect(renderer, NULL);
	


	SDL_Texture* tex = layers->ready_texture();

	SDL_SetRenderTarget(renderer, parent->texture);
	
	SDL_Rect copy_rect = { x, y, (int)(width * size_factor), (int)(height * size_factor) };

	SDL_RenderCopy(renderer, background, NULL, &copy_rect);

	
	SDL_RenderCopy(renderer, tex, NULL, &copy_rect);


//	SDL_RenderPresent(renderer);

	SDL_SetRenderTarget(renderer, NULL);

//	SDL_DestroyTexture(tex);

}

void Canvas::save_png()
{
	Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	int shift = 8;
	rmask = 0xff000000 >> shift;
	gmask = 0x00ff0000 >> shift;
	bmask = 0x0000ff00 >> shift;
	amask = 0x000000ff >> shift;
#else // little endian, like x86
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif

	SDL_Texture* ready = layers->ready_texture();

	void* pixels = nullptr;

	SDL_SetRenderTarget(renderer, ready);
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_RGBA8888, pixels, 4);
	SDL_Rect size = layers->get_size_layers();
	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(pixels, size.w, size.h, 32, 4, rmask, gmask, bmask, amask);
	SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_BLEND);
	IMG_SavePNG(surface, "ready.png");

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

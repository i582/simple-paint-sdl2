#include "layer.h"

Layer::Layer(SDL_Texture* texture, int id, string name, Uint8 alpha, SDL_BlendMode blend_mode)
{
	if (name == "") this->name = "Layer " + to_string(id);
	else this->name = name;

	this->id = id;


	this->alpha = alpha;
	this->texture = texture;
	this->blend_mode = blend_mode;

	SDL_QueryTexture(this->texture, NULL, NULL, &size.w, &size.h);

	this->display = true;
	this->blocked = false;
}

void Layer::set_alpha(Uint8 alpha)
{
	this->alpha = alpha;
}

void Layer::set_blend_mode(SDL_BlendMode blend_mode)
{
	this->blend_mode = blend_mode;
}

void Layer::block()
{
	blocked = true;
}

void Layer::inlock()
{
	blocked = false;
}

bool Layer::is_block()
{
	return blocked;
}

void Layer::show()
{
	display = true;
}

void Layer::hide()
{
	display = false;
}

bool Layer::is_show()
{
	return display;
}

void Layer::shift(int dx, int dy)
{
	size.x += dx;
	size.y += dy;
}

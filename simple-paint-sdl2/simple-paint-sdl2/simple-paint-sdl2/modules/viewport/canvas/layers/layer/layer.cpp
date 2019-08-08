#include "layer.h"

int Layer::s_id = 0;

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

bool Layer::is_display()
{
	return display;
}

void Layer::shift(int dx, int dy)
{
	size.x += dx;
	size.y += dy;
}

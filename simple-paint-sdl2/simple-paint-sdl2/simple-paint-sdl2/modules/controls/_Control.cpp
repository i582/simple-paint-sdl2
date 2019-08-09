#include "_Control.h"

_Control::_Control(SDL_Renderer* renderer, SDL_Rect size, string text, string font, int font_size)
{
	this->renderer = renderer;

	this->font_size = font_size;
	this->size = size;

	this->text = text;
	this->font = TTF_OpenFont(font.c_str(), font_size);
	this->align = 0;

	this->blocked = false;
	this->display = true;

	this->texture = nullptr;

}

_Control::~_Control()
{
	if (font != nullptr)
		TTF_CloseFont(font);
}

void _Control::block()
{
	blocked = true;
}

void _Control::unlock()
{
	blocked = false;
}

bool _Control::is_block()
{
	return blocked;
}

void _Control::show()
{
	display = true;
}

void _Control::hide()
{
	display = false;
}

bool _Control::is_show()
{
	return display;
}

bool _Control::is_hover(int x, int y)
{
	SDL_Point point = { x, y };
	return SDL_PointInRect(&point, &size) && !blocked && display;
}

#include "toolbar.h"

Toolbar::Toolbar(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	this->sizes = { 0, 30, 40, 640};
	this->sizes_one_tool = { 0, 0, 30, 25 };

	this->selected_tool = NULL_TOOLS;
}

void Toolbar::init()
{

}

bool Toolbar::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &sizes);
}

int Toolbar::get_tool()
{
	return selected_tool;
}

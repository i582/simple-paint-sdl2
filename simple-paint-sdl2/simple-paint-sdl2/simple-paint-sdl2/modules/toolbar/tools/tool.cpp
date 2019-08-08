#include "tool.h"

Tool::Tool(SDL_Renderer* renderer, int type, int x, int y)
{
	this->renderer = renderer;
	this->sizes = { x, y, 30, 25 };
	this->icon = IMG_LoadTexture(renderer, "../sfx/tool_icons/rect.png");
	this->type = type;

	this->hover = false;
	this->selected = false;
}

void Tool::render()
{
	if (selected)
		SDL_SetRenderDrawColor(renderer, Colors::tool_selected.r, Colors::tool_selected.g, Colors::tool_selected.b, Colors::tool_selected.a);
	else if (hover)
		SDL_SetRenderDrawColor(renderer, Colors::tool_hover.r, Colors::tool_hover.g, Colors::tool_hover.b, Colors::tool_hover.a);
	else
		SDL_SetRenderDrawColor(renderer, Colors::tool.r, Colors::tool.g, Colors::tool.b, Colors::tool.a);

	SDL_RenderFillRect(renderer, &sizes);

	SDL_SetRenderDrawColor(renderer, Colors::tool_border.r, Colors::tool_border.g, Colors::tool_border.b, Colors::tool_border.a);
	SDL_RenderDrawRect(renderer, &sizes);

	SDL_RenderPresent(renderer);
}

void Tool::set_hover(bool value)
{
	hover = value;
}

void Tool::set_selected(bool value)
{
	selected = value;
}

bool Tool::is_selected()
{
	return selected;
}

int Tool::get_tool_type()
{
	return type;
}

bool Tool::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &sizes);
}

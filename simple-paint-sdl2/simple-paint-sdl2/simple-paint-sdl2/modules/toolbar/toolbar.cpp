#include "toolbar.h"

Toolbar::Toolbar(SDL_Renderer* renderer, SDL_Rect size)
{
	this->renderer = renderer;
	this->size = size;

	init();
}

Toolbar::~Toolbar()
{
	SDL_DestroyTexture(texture);
}

void Toolbar::init()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);

	SDL_SetRenderTarget(renderer, texture);

	SDL_SetRenderDrawColor(renderer, Colors::background.r, Colors::background.g, Colors::background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);

	SDL_RenderPresent(renderer);

	tools.push_back(new Tool(renderer, TOOL_0, 5, 5));
	tools.push_back(new Tool(renderer, TOOL_1, 5, 35));
	tools.push_back(new Tool(renderer, TOOL_2, 5, 65));
	tools.push_back(new Tool(renderer, TOOL_3, 5, 95));
	tools.push_back(new Tool(renderer, TOOL_4, 5, 125));
}

void Toolbar::update()
{
	render_tools();

	SDL_RenderCopy(renderer, texture, NULL, &size);

	SDL_RenderPresent(renderer);
}

void Toolbar::render_tools()
{
	SDL_SetRenderTarget(renderer, texture);

	for (auto& tool : tools)
	{
		tool->render();
	}

	SDL_SetRenderTarget(renderer, NULL);
}

void Toolbar::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
	update_coord(&mouse_coord.x, &mouse_coord.y);

}

void Toolbar::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
	update_coord(&mouse_coord.x, &mouse_coord.y);

	for (auto& tool : tools)
	{
		if (tool->on_hover(mouse_coord.x, mouse_coord.y))
		{
			tool->set_selected(true);
		}
		else
		{
			tool->set_selected(false);
		}
	}

	update();
}

void Toolbar::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
	update_coord(&mouse_coord.x, &mouse_coord.y);

	for (auto& tool : tools)
	{
		if (tool->on_hover(mouse_coord.x, mouse_coord.y))
			tool->set_hover(true);
		else
			tool->set_hover(false);
	}

	update();
}

bool Toolbar::on_hover(int x, int y)
{
	SDL_Point p = { x, y };
	return SDL_PointInRect(&p, &size);
}

int Toolbar::get_tool()
{
	for (auto& tool : tools)
		if (tool->is_selected())
			return tool->get_tool_type();
}

void Toolbar::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

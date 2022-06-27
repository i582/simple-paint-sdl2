#include "toolbar.h"
#include "ctime"

Toolbar::Toolbar(Window* parent, SDL_Rect size)
{
	this->parent = parent;
	this->renderer = parent->getRenderer();
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

//	SDL_RenderPresent(renderer);


	auto tools1 = new vector<Control*>;

	Tool* tool1 = new Tool(parent, texture, 1, 128, { (size.w - 30) / 2, 0, 30, 25 }, tools1, TOOL_MOVE);
	Tool* tool2 = new Tool(parent, texture, 1, 129, { (size.w - 30) / 2, 27, 30, 25 }, tools1, TOOL_SELECT);
	Tool* tool3 = new Tool(parent, texture, 1, 130, { (size.w - 30) / 2, 54, 30, 25 }, tools1, TOOL_DRAW);
	Tool* tool4 = new Tool(parent, texture, 1, 131, { (size.w - 30) / 2, 81, 30, 25 }, tools1, TOOL_RECTANGLE);
	Tool* tool5 = new Tool(parent, texture, 1, 132, { (size.w - 30) / 2, 108, 30, 25 }, tools1, TOOL_LINE);
	tools1->push_back(tool1);
	tools1->push_back(tool2);
	tools1->push_back(tool3);
	tools1->push_back(tool4);
	tools1->push_back(tool5);
	tools.push_back(tool1);
	tools.push_back(tool2);
	tools.push_back(tool3);
	tools.push_back(tool4);
	tools.push_back(tool5);
}

void Toolbar::update()
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, Colors::background.r, Colors::background.g, Colors::background.b, 0xFF);
	SDL_RenderFillRect(renderer, NULL);
	SDL_SetRenderTarget(renderer, NULL);

	render_tools();

	SDL_RenderCopy(renderer, texture, NULL, &size);

//	SDL_RenderPresent(renderer);
}

void Toolbar::render_tools()
{
	SDL_SetRenderTarget(renderer, texture);

	for (auto& tool : tools)
	{
		tool->update();
	}

	SDL_SetRenderTarget(renderer, NULL);
}

void Toolbar::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
	update_coord(&mouse_coord.x, &mouse_coord.y);

	for (auto& tool : tools)
	{
		if (tool->on_hover(mouse_coord.x, mouse_coord.y))
		{
			tool->do_update()->mouseButtonDown(e);
		}
	}

	update();
}

void Toolbar::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
	update_coord(&mouse_coord.x, &mouse_coord.y);

	for (auto& tool : tools)
	{
		if (tool->on_hover(mouse_coord.x, mouse_coord.y))
		{
			tool->do_update()->mouseButtonUp(e);
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
		{
			tool->hover();
		}
		else
		{
			tool->unhover();
		}
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
	return 0;
}

void Toolbar::update_coord(int* x, int* y)
{
	*x -= this->size.x;
	*y -= this->size.y;
}

#include "tool.h"
#include "../../editor/editor.h"

Tool::Tool(Window* parent, SDL_Texture* parent_target, int group_ID, int tool_ID, SDL_Rect size, vector <Control*>* friends, int style, bool checked)
	: RadioButton(parent, parent_target, group_ID, tool_ID, size, friends, style, checked)
{
	setup();
}

void Tool::setup()
{
	switch (style)
	{
	case TOOL_MOVE:
	{
		border = false;
		image_select = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/move.png");
		image_unselect = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/move.png");

		break;
	}

	case TOOL_SELECT:
	{
		border = false;
		image_select = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/select.png");
		image_unselect = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/select.png");

		break;
	}

	case TOOL_DRAW:
	{
		border = false;
		image_select = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/draw.png");
		image_unselect = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/draw.png");

		break;
	}

	case TOOL_RECTANGLE:
	{
		border = false;
		image_select = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/rect.png");
		image_unselect = IMG_LoadTexture(renderer, "/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/tool_icons/rect.png");

		break;
	}

	default:
	
		break;
	}


	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
}

void Tool::update_()
{
	if (!display)
		return;

	SDL_SetRenderTarget(renderer, texture);

	

	if (checked || hovered)
	{
		SDL_SetRenderDrawColor(renderer, Colors::tool_selected.r, Colors::tool_selected.g, Colors::tool_selected.b, 0xFF);
		SDL_RenderFillRect(renderer, NULL);
		SDL_SetRenderDrawColor(renderer, Colors::tool_border.r, Colors::tool_border.g, Colors::tool_border.b, 0xFF);
		SDL_RenderDrawRect(renderer, NULL);

		int select_width, select_height;
		SDL_QueryTexture(image_select, nullptr, nullptr, &select_width, &select_height);
		SDL_Rect r = { (int)(size.w / 2. - select_width / 2.), (int)(size.h / 2. - select_height / 2.), select_width, select_height };
		SDL_RenderCopy(renderer, image_select, NULL, &r);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, Colors::tool.r, Colors::tool.g, Colors::tool.b, 0xFF);
		SDL_RenderFillRect(renderer, NULL);

		int unselect_width, unselect_height;
		SDL_QueryTexture(image_unselect, nullptr, nullptr, &unselect_width, &unselect_height);
		SDL_Rect r = { (int)(size.w / 2. - unselect_width / 2.), (int)(size.h / 2. - unselect_height / 2.), unselect_width, unselect_height };
		SDL_RenderCopy(renderer, image_unselect, NULL, &r);
	}

	if (border)
	{
		SDL_SetRenderDrawColor(renderer, Colors::viewport_border.r, Colors::viewport_border.g, Colors::viewport_border.b, 0xFF);
		SDL_RenderDrawRect(renderer, NULL);
	}

//	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, parent_target);
}

void Tool::mouseButtonDown(SDL_Event* e)
{
	is_updated = false;

	for (auto& friend_ : *friends)
	{
		friend_->uncheck();
	}

	Editor::push_event(new Event(TOOL, TOOL_SELECTED, control_ID));


	checked = true;

	check_click_out();
}

void Tool::mouseButtonUp(SDL_Event* e)
{
	
}

void Tool::mouseMotion(SDL_Event* e)
{
	hovered = true;
}

void Tool::keyDown(SDL_Event* e)
{
}

void Tool::keyUp(SDL_Event* e)
{
}

void Tool::textInput(SDL_Event* e)
{
}


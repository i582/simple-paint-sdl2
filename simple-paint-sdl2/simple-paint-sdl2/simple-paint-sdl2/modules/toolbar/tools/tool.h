#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "../../colors/color.h"

enum TOOLS
{
	TOOL_0,
	TOOL_1,
	TOOL_2,
	TOOL_3,
	TOOL_4,
	TOOL_5,
};

class Tool 
{
private:
	SDL_Renderer* renderer;
	SDL_Rect sizes;
	SDL_Texture* icon;

	int type;

	bool hover;
	bool selected;
	
public:
	Tool(SDL_Renderer* renderer, int type, int x, int y);

public:
	void render();

	void set_hover(bool value);
	void set_selected(bool value);

	bool is_selected();
	int get_tool_type();

	bool on_hover(int x, int y);
};
#pragma once
#include "SDL.h"

struct Colors 
{
	static SDL_Color white;


	static SDL_Color element_background;
	static SDL_Color element_d_background;
	static SDL_Color element_border;


	static SDL_Color background;
	static SDL_Color element_blocked;
	
	static SDL_Color element_background_click;
	static SDL_Color element_background_focus;
	static SDL_Color element_background_unfocus;
	static SDL_Color element_border_click;
	static SDL_Color element_list_hover;
	static SDL_Color element_text;

	static SDL_Color canvas_background;
	static SDL_Color canvas_black;

	static SDL_Color viewport_back;
	static SDL_Color viewport_border;


	
	static SDL_Color scroll_back;
	static SDL_Color scroll_slider;
	static SDL_Color scroll_corner;

	
	static SDL_Color tool;
	static SDL_Color tool_hover;
	static SDL_Color tool_selected;
	static SDL_Color tool_border;
	
};
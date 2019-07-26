#pragma once

#include "SDL.h"
#include "iostream"
#include "vector"
#include "../interface/color.h"

class Viewport;

class Scroll {
private:
	SDL_Renderer* renderer;
	COLOR Colors;
	SDL_Rect sizes;

	SDL_Rect slider_sizes;

	int max_value;
	int now_value;
	int size_one_step;

	bool is_push;

	SDL_Point pos_mouse;

	SDL_Texture* parent_target;
	SDL_Rect parent_sizes;

	Viewport* parent;

public:
	Scroll(SDL_Renderer* renderer, int width, int height, int x, int y, int now_value, int max_value, int size_one_step);

public:
	void render();

	void set_parent(Viewport* parent);

	bool v_scroll_hover(int x, int y);
	bool v_slider_hover(int x, int y);

	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);

	/**
	 *  \ѕреобразует координаты мыши в координаты относительно верхнего левого угла родительского объекта
	 */
	void update_coord(int* x, int* y);
};
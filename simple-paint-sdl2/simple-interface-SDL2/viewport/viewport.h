#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../interface/color.h"
#include "../canvas/canvas.h"
#include "../control_elements/scroll.h"
using namespace std;

class Scroll;

class Viewport {
private:
	int width;
	int height;

	int x;
	int y;

	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Canvas* canvas;

	double size_factor;

	SDL_Point pos_mouse;

	COLOR Colors;

	Scroll* v_scroll;

public:
	Viewport(SDL_Renderer* renderer, int x, int y, int width, int height);
	~Viewport();

public:
	friend Scroll;

private:
	void init();

public:
	void update();
	void clear();

	void render_scrolls();

	void set_canvas(Canvas* new_canvas);
	SDL_Texture* get_render_target();

	/* События */
	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);
	void mouseWheel(SDL_Event* event);
	void keyDown(SDL_Event* event);


	/* Вспомогательные */
	bool on_hover(int x, int y);

	void set_canvas_position(int x, int y);
	void set_canvas_size_factor(double size_factor, int direction);
	void canvas_update();

	/**
	 *  \Преобразует координаты мыши в координаты относительно верхнего левого угла вьюпорта
	 */
	void update_coord(int* x, int* y);
};
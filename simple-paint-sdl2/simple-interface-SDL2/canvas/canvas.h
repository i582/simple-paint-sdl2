#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../interface/color.h"
#include "../primitives/primitives.h"

using namespace std;

class Canvas {
private:
	int width;
	int height;

	int x;
	int y;

	SDL_Renderer* renderer;
	SDL_Texture* texture;

	double size_factor;

	SDL_Point pos_mouse;

	COLOR Colors;

	SDL_Texture* parentTarget;

public:
	Canvas(SDL_Renderer* renderer, SDL_Texture* parentTarget, int x, int y, int width, int height);
	~Canvas();

private:
	void init();

public:
	void update();

	/* События */
	void mouseButtonDown(SDL_Event* event, SDL_Point pos_mouse);
	void mouseButtonUp(SDL_Event* event, SDL_Point pos_mouse);
	void mouseMotion(SDL_Event* event, SDL_Point pos_mouse);
	void keyDown(SDL_Event* event);

	/* Вспомогательные */
	bool on_hover(int x, int y);
	void set_position(int x, int y);
	void set_size_factor(double size_factor);

	void shift_position(int x, int y);

	void center_align(int width, int height);
	bool full_in_viewport(int width, int height);

	void get_size(int* width, int* height);
	void get_position(int* x, int* y);
	double get_size_factor();

	/**
	 *  \Преобразует координаты мыши в координаты относительно верхнего левого угла canvas
	 */
	void update_coord(int* x, int* y);
};
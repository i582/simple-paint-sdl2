#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../../colors/color.h"
#include "../../primitives/primitives.h"

#include "layers/layers.h"

using namespace std;

class Viewport;

class Canvas {
private:
	int width;
	int height;

	int x;
	int y;

	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Layers* layers;

	double size_factor;

	SDL_Point pos_mouse;

	Viewport* parent;


	bool is_selected;
	int selected_id;

public:
	Canvas(SDL_Renderer* renderer, Viewport* parent, int x, int y, int width, int height);
	~Canvas();

private:
	void init();

public:
	void update();

	/* События */
	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void keyDown(SDL_Event* e);

	/* Вспомогательные */
	bool on_hover(int x, int y);
	void set_position(int x, int y);
	void set_size_factor(double size_factor);

	void shift_position(int x, int y);

	void center_align();
	bool full_in_viewport();


	int get_width();
	int get_height();

	void get_position(int* x, int* y);
	int get_y();
	int get_x();
	double get_size_factor();

	bool get_selected();
	Layers* get_layers();

	/**
	 *  \Преобразует координаты мыши в координаты относительно верхнего левого угла canvas
	 */
	void update_coord_with_scale(int* x, int* y);

	void update_coord(int* x, int* y);

};
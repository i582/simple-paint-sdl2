#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "../../colors/color.h"
#include "../../viewport/canvas/canvas.h"

using namespace std;

class Viewport;
class LayersViewer;

class WorkTable
{
private:
	SDL_Rect size;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	Canvas* canvas;
	Viewport* viewport;

	double size_factor;

public:
	WorkTable(Viewport* parent, SDL_Rect size);
	~WorkTable();

public:
	friend Canvas;
	friend Viewport;
	friend LayersViewer;

private:
	void init();

public:
	void update();
	void clear();
	void centering();

	void set_position(int x, int y);
	void set_size_factor(double factor);
	Canvas* get_canvas();

	double get_size_factor();
	int get_width();
	int get_height();

	int get_y();
	int get_x();

	void update_coord(int* x, int* y);

	bool on_hover(int x, int y);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);
};

#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../colors/color.h"
#include "../viewport/canvas/canvas.h"
#include "../viewport/scrolls/v_view_scroll.h"
#include "../viewport/scrolls/h_view_scroll.h"
#include "../controls/scale_info.h"
#include "../layer_viewer/layer_viewer.h"

using namespace std;

class V_ViewScroll;
class H_ViewScroll;


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

	V_ViewScroll* v_scroll;
	H_ViewScroll* h_scroll;
	
	ScaleInfo* scale_info;
	LayerViewer* layer_viewer;

public:
	Viewport(SDL_Renderer* renderer, int x, int y, int width, int height);
	~Viewport();

public:
	friend V_ViewScroll;
	friend H_ViewScroll;
	friend Canvas;



private:
	void init();

public:
	void update();
	void clear();

	void render_scrolls();

	void set_canvas(Canvas* new_canvas);
	void set_layer_viewer(LayerViewer* layer_viewer);

	SDL_Texture* get_render_target();
	SDL_Rect get_size();

	/* События */
	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);


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
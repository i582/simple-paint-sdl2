#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../colors/color.h"
#include "canvas/canvas.h"
#include "scrolls/v_view_scroll.h"
#include "scrolls/h_view_scroll.h"
#include "../controls/scale_info.h"
#include "../layers_viewer/layers_viewer.h"

using namespace std;

class V_ViewScroll;
class H_ViewScroll;

class Editor;

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
	LayersViewer* layers_viewer;

public:
	Viewport(SDL_Renderer* renderer, int x, int y, int width, int height);
	~Viewport();

public:
	friend V_ViewScroll;
	friend H_ViewScroll;
	friend Canvas;
	friend ScaleInfo;



public:
	void init();
	void update();
	void clear();

	void setup_scrolls();
	void render_scrolls();

	void set_canvas(Canvas* new_canvas);
	void set_canvas_size_factor(double size_factor);

	void set_layer_viewer(LayersViewer* layers_viewer);

	const SDL_Texture* const get_render_target();
	SDL_Rect get_size();

	Canvas* const get_canvas();

	/* ������� */
	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);


	/* ��������������� */
	bool on_hover(int x, int y);

	/**
	 *  \����������� ���������� ���� � ���������� ������������ �������� ������ ���� ��������
	 */
	void update_coord(int* x, int* y);




	void set_size(int width, int height);
};
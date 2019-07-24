#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../interface/color.h"
using namespace std;

class Viewport {
private:
	int width;
	int height;

	int x;
	int y;

	SDL_Renderer* renderer;
	SDL_Texture* texture;

	SDL_Texture* canvas;

	double size_factor;

	SDL_Point pos_mouse;

public:
	Viewport(SDL_Renderer* renderer, int width, int height, int x, int y);
	~Viewport();

public:
	void init();
	void update();

	/* События */
	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);
	void keyDown(SDL_Event* event);


	/* Вспомогательные */
	bool on_hover(int x, int y);

	/**
	 *  \Преобразует координаты мыши в координаты относительно верхнего левого угла вьюпорта
	 */
	void update_coord(int* x, int* y);
};
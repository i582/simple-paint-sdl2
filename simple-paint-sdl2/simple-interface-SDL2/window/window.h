#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../color_scheme/color.h"
using namespace std;

class Window {
public:
	int width;
	int height;

	int x;
	int y;

	string title;

private:
	Uint32 flags;
	SDL_Color background_color;

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Point mouse_coord;
	

	/*no-border*/
	bool no_border;

	SDL_Rect close_button_coord;
	bool hover_close;

public:
	Window(string title, SDL_Rect* sizes, Uint32 flags);
	Window(string title, SDL_Rect* sizes, Uint32 flags, SDL_Color* background_color);
	~Window();

private:
	void render();
	void render_toolup();
	int SDL_WindowHitTest (SDL_Window* win, void* callback_data);
	int SDL_SetDrawColor(SDL_Renderer* renderer, SDL_Color color);

public:
	bool init();

	void show();
	void hide();
	void close();

	void update();
	SDL_Renderer* getRenderer();

	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);
	void mouseWheel(SDL_Event* event);
};
#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../interface/color.h"
using namespace std;

class Window {
private:
	int width;
	int height;

	string title;

	int x;
	int y;

	Uint32 flags;

	bool no_border;

	COLOR Colors;
	SDL_Color background_color;

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Point mouse_coord;
	SDL_Rect close_button_coord;

	/*no-border*/
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
};
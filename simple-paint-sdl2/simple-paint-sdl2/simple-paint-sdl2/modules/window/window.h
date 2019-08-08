#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../colors/color.h"
using namespace std;

class Window {
public:
	int width;
	int height;

	int x;
	int y;

	string title;

protected:
	Uint32 flags;

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Point mouse_coord;
	

	/*no-border*/
	bool no_border;
	SDL_Rect close_button_coord;
	bool hover_close;

public:
	Window(string title, SDL_Rect* sizes, Uint32 flags);
	~Window();

protected:
	int SDL_WindowHitTest (SDL_Window* win, void* callback_data);
	int SDL_SetDrawColor(SDL_Renderer* renderer, SDL_Color color);

public:
	virtual bool init();
	virtual void setup() = 0;
	void show();
	void hide();
	void close();

	virtual void render();
	void update();

	SDL_Renderer* getRenderer();
	
	virtual void mouseButtonDown(SDL_Event* e);
	virtual void mouseButtonUp(SDL_Event* e);
	virtual void mouseMotion(SDL_Event* e);
	virtual void mouseWheel(SDL_Event* e);
	virtual void keyDown(SDL_Event* e);
	virtual void keyUp(SDL_Event* e);
};
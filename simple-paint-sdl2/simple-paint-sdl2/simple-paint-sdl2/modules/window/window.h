#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../colors/color.h"

#include "../resources/resources.h"
#include "../primitives/primitives.h"
#include "../events/events.h"

using namespace std;

class Window 
{

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
	SDL_Texture* icon_texture;

	bool display;

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
	bool init();
	virtual void setup() = 0;

	void show();
	void hide();
	bool is_show();

	void close();

	virtual void render() = 0;

	void set_position(int x, int y);
	SDL_Renderer* getRenderer();
	SDL_Window* get_window();
	
	virtual void mouseButtonDown(SDL_Event* e) = 0;
	virtual void mouseButtonUp(SDL_Event* e) = 0;
	virtual void mouseMotion(SDL_Event* e) = 0;
	virtual void mouseWheel(SDL_Event* e) = 0;
	virtual void keyDown(SDL_Event* e) = 0;
	virtual void keyUp(SDL_Event* e) = 0;
	virtual void textInput(SDL_Event* e) = 0;

	virtual void handleUserEvents(Event* ev) = 0;
};
#pragma once
#include "vector"
#include "../window/window.h"


class DropWindow : public Window {
private:
	

public:
	DropWindow(string title, SDL_Rect* sizes, Uint32 flags);

public:
	void setup();
	void render();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void textInput(SDL_Event* e);

	void handleUserEvents(Event* ev);

	void on_event(SDL_Event* e);
};
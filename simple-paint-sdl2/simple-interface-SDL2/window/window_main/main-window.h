#pragma once
#include "vector"
#include "../window.h"
#include "../../viewport/viewport.h"

#include "../../tools/tool.h"

class MainWindow : public Window {
private:
	Viewport* viewport;
	Canvas* canvas;


	vector <Tool*> tools;

public:
	MainWindow(string title, SDL_Rect* sizes, Uint32 flags);

public:
	bool init();
	void setup();
	void render();

	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);
	void mouseWheel(SDL_Event* event);
	void keyDown(SDL_Event* event);
	void keyUp(SDL_Event* event);
};
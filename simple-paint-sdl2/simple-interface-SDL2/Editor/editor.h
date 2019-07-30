#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "../color_scheme/color.h"
#include "../window/window_main/main-window.h"
#include "../primitives/primitives.h"

using namespace std;

class Editor {
private:
	bool running;
	MainWindow* main_window;
	SDL_Event e;

public:
	Editor(int width, int height);
	~Editor();

private:
	bool init();
	void setup();
	void update();
	void onEvent();
	void quit();

public:
	int onExecute();

};
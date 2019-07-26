#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "../color_scheme/color.h"
#include "../window/window.h"
#include "../primitives/primitives.h"
#include "../viewport/viewport.h"

using namespace std;

class Editor {
private:
	bool running;
	Window* window;
	SDL_Event event;

	Viewport* viewport;
	Canvas* canvas;

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
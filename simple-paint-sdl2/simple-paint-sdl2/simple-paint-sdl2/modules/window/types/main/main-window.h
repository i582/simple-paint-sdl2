#pragma once
#include "vector"
#include "../../window.h"
#include "../../../viewport/viewport.h"

#include "../../../toolbar/toolbar.h"
#include "../../../layers_viewer/layers_viewer.h"
#include "../../../container/container.h"


class MainWindow : public Window {
private:
	int width;
	int height;


	Viewport* viewport;
	Canvas* canvas;

	LayersViewer* layers_viewer;

	Toolbar* toolbar;

	Container* container;
	

public:
	MainWindow(string title, SDL_Rect* sizes, Uint32 flags);

public:
	void setup();
	void render();

	void resized();
	void set_size(int width, int height);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void systemEvent(SDL_Event* e);
};
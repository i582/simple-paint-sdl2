#pragma once
#include "vector"
#include "../../window.h"
#include "../../../viewport/viewport.h"

#include "../../../toolbar/tools/tool.h"
#include "../../../layer_viewer/layer_viewer.h"

class MainWindow : public Window {
private:
	Viewport* viewport;
	Canvas* canvas;

	LayerViewer* layer_viewer;

	vector <Tool*> tools;
	

public:
	MainWindow(string title, SDL_Rect* sizes, Uint32 flags);

public:
	void setup();
	void render();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
};
#pragma once
#include "vector"
#include "../../window.h"
#include "../../../viewport/viewport.h"

#include "../../../toolbar/toolbar.h"
#include "../../../layers_viewer/layers_viewer.h"
#include "../../../menubar/menubar.h"

#include "../../../controls/DropDown.h"
#include "../../../controls/button.h"
#include "../../../controls/button_image.h"

#include "../../../controls/RadioButton.h"

class MainWindow : public Window 
{
public:
	static DropWindow* drop_window;

private:
	Viewport* viewport;
	Canvas* canvas;

	LayersViewer* layers_viewer;

	Toolbar* toolbar;
	MenuBar* menubar;

	DropDownList* dropdown;

	vector <Control*> controls;
	Control* focus_element;

	SDL_Texture* back;

public:
	MainWindow(string title, SDL_Rect* sizes, Uint32 flags);

public:
	friend Control;
	friend MenuBar;
	friend DropDownList;

public:
	void update();
	void setup();
	void render();

	void resized();
	void set_size(int width, int height);

	Control* const CreateControl(Control* el);

	static SDL_HitTestResult HitTest(SDL_Window* window, const SDL_Point* area, void* data);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);

	void handleUserEvents(Event* ev);
};
#pragma once

#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "../colors/color.h"
#include "../window/types/main/main-window.h"
#include "../window/types/new_doc/WindowNewDocument.h"

#include "../controls/DropWindow.h"
#include "../primitives/primitives.h"

#include "../resources/resources.h"

#include "../events/events.h"

using namespace std;


enum Window_IDs
{
	WINDOW_NEW_DOCUMENT = 1,
	WINDOW_MAIN
};


class Editor 
{
public:
	static vector <Event*> events;
	static Event* push_event(Event* ev);


	// singleton part
private:
	static Editor* instance;
	Editor(int width, int height);

public:
	static Editor* get_instance();
	~Editor();
	


private:
	int width;
	int height;

	bool running;
	MainWindow* main_window;
	NewDocumentWindow* new_document;

	SDL_Event e;

	int selected_tool;

public:
	friend NewDocumentWindow;

private:
	bool init();
	void setup();
	void update();
	void onEvent();
	void sendHandleUserEvent();
	void quit();

public:
	int run();

};
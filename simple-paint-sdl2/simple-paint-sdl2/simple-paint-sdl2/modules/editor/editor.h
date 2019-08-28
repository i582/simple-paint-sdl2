#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "../colors/color.h"
#include "../window/types/main/main-window.h"
#include "../controls/DropWindow.h"
#include "../primitives/primitives.h"

#include "../events/events.h"

using namespace std;

class Editor 
{
public:
	static vector <Event*> events;
	static Event* push_event(Event* ev);

private:
	bool running;
	MainWindow* main_window;
	SDL_Event e;

	int selected_tool;

public:
	Editor(int width, int height);
	~Editor();

private:
	bool init();
	void setup();
	void update();
	void onEvent();
	void sendHandleUserEvent();
	void quit();

public:
	int onExecute();

};
#pragma once
#include "SDL.h"

#include "iostream"
#include "vector"
#include "../colors/color.h"

#include "../controls/DropDown.h"
#include "../controls/button_image.h"

using namespace std;

class MenuBar : public Control
{
private:
	vector <Control*> menu_elements;
	Window* parent_window;

public:
	MenuBar(Window* parent_window, SDL_Rect size, int object_ID);

private:
	void init();

public:
	void update_();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void textInput(SDL_Event* e);
};

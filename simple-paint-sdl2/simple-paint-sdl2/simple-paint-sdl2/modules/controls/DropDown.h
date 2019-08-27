#pragma once
#include "_Control.h"
#include "DropWindow.h"

class DropDownList : public Control
{
private:
	Window* parent;
	bool opened;

public:
	DropDownList(Window* parent, SDL_Texture* parent_target, string text, int control_ID, SDL_Rect size);

private:
	void setup();

public:
	void update_();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void textInput(SDL_Event* e);
};


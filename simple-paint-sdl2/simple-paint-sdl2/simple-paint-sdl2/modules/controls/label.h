#pragma once
#include "_Control.h"

class Label : public Control
{
public:
	Label(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size, TTF_Font* font);

public:
	void update_();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void textInput(SDL_Event* e);
};
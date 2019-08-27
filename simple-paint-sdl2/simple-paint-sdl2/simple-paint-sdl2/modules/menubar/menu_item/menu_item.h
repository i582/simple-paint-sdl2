#pragma once
#include "SDL.h"

#include "iostream"
#include "vector"
#include "../../colors/color.h"

#include "../../controls/_Control.h"

using namespace std;


class MenuItem : public Control
{
private:


public:
	MenuItem(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, string text, int object_ID);

public:
	void update_();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void textInput(SDL_Event* e);

};
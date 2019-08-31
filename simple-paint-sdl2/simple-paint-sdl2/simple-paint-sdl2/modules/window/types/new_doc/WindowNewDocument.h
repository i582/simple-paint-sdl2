#pragma once
#include "vector"
#include "../../window.h"

#include "../../../controls/button.h"
#include "../../../controls/button_image.h"

#include "../../../controls/RadioButton.h"

#include "../../../controls/Label.h"
#include "../../../controls/Input.h"

#include "../../../window/types/main/main-window.h"

enum Controls_Id
{
	BUTTON_EXIT,
	LABEL_TEXT_CREATE,
	LABEL_TEXT_WIDTH,
	INPUT_WIDTH,
	LABEL_TEXT_HEIGHT,
	INPUT_HEIGHT,
	BUTTON_CREATE
};


class NewDocumentWindow : public Window
{

private:
	vector <Control*> controls;
	Control* focus_element;

	SDL_Texture* background;


public:
	NewDocumentWindow(string title, SDL_Rect* sizes, Uint32 flags);

public:
	friend Control;

private:
	void setup();

public:
	void update();
	void render();


	Control* const CreateControl(Control* el);

	static SDL_HitTestResult HitTest(SDL_Window* window, const SDL_Point* area, void* data);

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);
	void mouseWheel(SDL_Event* e);
	void keyDown(SDL_Event* e);
	void keyUp(SDL_Event* e);
	void textInput(SDL_Event* e);

	void handleUserEvents(Event* ev);
};
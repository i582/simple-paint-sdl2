#pragma once
#include "Checkbox.h"

class RadioButton : public Checkbox
{
private:
	

public:
	RadioButton(Window* parent, SDL_Texture* parent_target, int group_ID, int control_ID, SDL_Rect size, vector <Control*>* friends, int style = SIMPLE, bool checked = false);

private:
	virtual void setup();

public:
	virtual void update_(); 

	virtual void mouseButtonDown(SDL_Event* e);
	virtual void mouseButtonUp(SDL_Event* e);
	virtual void mouseMotion(SDL_Event* e);
	virtual void keyDown(SDL_Event* e);
	virtual void keyUp(SDL_Event* e);
	virtual void textInput(SDL_Event* e);
};

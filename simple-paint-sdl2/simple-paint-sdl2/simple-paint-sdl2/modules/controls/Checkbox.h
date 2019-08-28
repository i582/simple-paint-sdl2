#pragma once
#include "_Control.h"

enum CheckboxStyles
{
	SIMPLE = 0x00000001,
	EYE = 0x00000002,
	BLOCK = 0x00000003
};

class Checkbox : public Control
{

protected:
	SDL_Texture* image_select;
	SDL_Texture* image_unselect;


	int style;

	bool border;

public:
	Checkbox(SDL_Renderer* renderer, SDL_Texture* parent_target, int control_ID, SDL_Rect size = { 0, 0, -1, -1 }, int style = SIMPLE, bool checked = false);
	
	~Checkbox();

protected:
	void init();
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


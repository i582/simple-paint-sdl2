#pragma once
#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "../../colors/color.h"


#include "../../controls/RadioButton.h"


enum TOOLS
{
	TOOL_MOVE,
	TOOL_SELECT,
	TOOL_DRAW,
	TOOL_RECTANGLE,
	TOOL_LINE,
};

class Tool : public RadioButton
{
private:
	
public:
	Tool(Window* parent, SDL_Texture* parent_target, int group_ID, int tool_ID, SDL_Rect size, vector <Control*>* friends, int style = SIMPLE, bool checked = false);

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
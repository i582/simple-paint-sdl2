#pragma once
#include "_Control.h"

enum CheckboxStyles
{
	SIMPLE = 0x00000001,
	EYE = 0x00000002
};

class Checkbox : public _Control
{

private:
	SDL_Texture* parent_target;
	SDL_Texture* image_select;
	SDL_Texture* image_unselect;

	bool checked;

	int style;

	bool border;

public:
	Checkbox(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size = { 0, 0, -1, -1 }, int style = SIMPLE, bool checked = false, string text = "", string font = "", int font_size = 0);

	~Checkbox();

private:
	void setup();

public:
	void update();

	void mouseButtonDown(SDL_Event* e);
	void mouseButtonUp(SDL_Event* e);
	void mouseMotion(SDL_Event* e);

	void check();
	void uncheck();
	bool is_checked();
};


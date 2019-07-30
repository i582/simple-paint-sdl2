#pragma once
#include "base_control.h"

class Input : public Control {
private:
	bool focus;

public:
	Input(SDL_Rect _sizes, string _font, int _font_size, int _text_align) : Control(_sizes, "", _font, _font_size, _text_align)
	{
		focus = false;
	};

public:

	void render();
	void onEvent(SDL_Event* e);
	void in_focus();
	void out_focus();
	string get_value();
	void clear();
};
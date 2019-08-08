#pragma once
#include "base_control.h"

class Button : public Control {
public:
	Button(SDL_Rect _sizes, string _text, string _font, int _font_size, int _text_align) : Control(_sizes, _text, _font, _font_size, _text_align)
	{};
public:
	void render();
};
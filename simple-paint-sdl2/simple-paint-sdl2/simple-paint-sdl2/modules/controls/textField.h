#pragma once
#include "base_control.h"

class TextField : public Control {
private:
	vector <string> lines;
public:
	TextField(SDL_Rect _sizes, string _font, int _font_size, int _text_align) : Control(_sizes, "", _font, _font_size, _text_align)
	{};

public:
	void add(string newLine);

	void render();

};
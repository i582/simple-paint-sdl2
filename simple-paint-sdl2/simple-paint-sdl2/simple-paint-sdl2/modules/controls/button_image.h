#pragma once
#include "button.h"

class ButtonImg : public Button
{
private:
	SDL_Texture* img_texture;

public:
	ButtonImg(Window* parent, SDL_Texture* parent_target, int control_ID, string text, SDL_Rect size, SDL_Surface* image);
	~ButtonImg();

private:
	void init();

public:
	void update_();

};

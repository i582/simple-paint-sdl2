#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "../color_scheme/color.h"

using namespace std;

enum ALIGN_TYPE {
	CENTERED_ALIGN,
	LEFT_ALIGN
};



class Control{
public:
	static SDL_Renderer* renderer;

protected:
	SDL_Rect* sizes; 
	string label; 
	TTF_Font* font; 
	int font_size; 

	int text_align;

	bool block;
	bool display;
	bool click;

public:
	Control(SDL_Rect _sizes, string _label, string _font, int _font_size, int _text_align);
	~Control();

protected:
	// 
	bool SDL_SetRenderColor(SDL_Renderer* renderer, SDL_Color color);

	virtual void render();
	virtual void renderLabel(string text, SDL_Rect* place);
	virtual void renderLabel(string text, SDL_Rect* place, int _text_align);
	virtual void onEvent(SDL_Event* e);

public:

	void Block();
	void Unlock();
	bool is_block();

	void Show();
	void Hide();
	bool is_show();

	void Click(bool value);


	bool is_hover(int x, int y);
};
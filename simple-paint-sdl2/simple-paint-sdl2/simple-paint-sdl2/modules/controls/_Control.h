#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "vector"
#include "string"

#include "../styles/styles.h"

#include "../window/window.h"

using namespace std;

enum Align
{
	LEFT_ALIGN,
	LEFT_NO_PAD_ALIGN,
	CENTER_ALIGN
};

class Control
{
protected:
	SDL_Texture* texture;
	SDL_Texture* parent_target;
	SDL_Renderer* renderer;

	SDL_Texture* text_texture;
	SDL_Rect text_rect; 

	SDL_Rect size;

	string text;
	TTF_Font* font;

	SDL_Point mouse_p;

	int control_ID;
	int group_ID;

	bool blocked;
	bool display;
	bool click;
	bool focused;
	bool hovered;
	bool checked;

	bool is_updated;

	vector <Control*>* friends;

public:
	Control(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, string text, int control_ID);
	virtual ~Control();

private:
	void init();


protected:
	void render_text(string text, SDL_Rect place, int align, int font_size = Styles::font_size);
	void render_text_(string text, SDL_Rect place, int align, int font_size = Styles::font_size);

public:
	void update();
	virtual void update_() = 0;
	virtual Control* const clear();

	string& get_value();

	virtual void mouseButtonDown(SDL_Event* e) = 0;
	virtual void mouseButtonUp(SDL_Event* e) = 0;
	virtual void mouseMotion(SDL_Event* e) = 0;
	virtual void keyDown(SDL_Event* e) = 0;
	virtual void keyUp(SDL_Event* e) = 0;
	virtual void textInput(SDL_Event* e) = 0;

	Control* const block();
	Control* const unlock();
	bool is_block();

	Control* const show();
	Control* const hide();
	bool is_show();

	Control* const focus();
	Control* const unfocus();
	bool is_focus();

	Control* const check();
	Control* const uncheck();
	bool is_checked();

	Control* const hover();
	Control* const unhover();
	bool is_hover_();

	Control* const do_update();

	int get_group_id();

	auto get_friends();
	bool have_friends();

	virtual bool on_hover(int x, int y);
	void update_coord(int* x, int* y);
	void check_click_out();
};
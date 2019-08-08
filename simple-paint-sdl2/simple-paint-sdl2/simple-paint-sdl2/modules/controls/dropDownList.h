#pragma once
#include "base_control.h"


enum DROP_TYPE {
	NULL_EL,
	LEFT_SIDE,
	DOWN_SIDE 
};

struct DropDownItem {
	DropDownItem() {
		text = "";
		hover = false;
		block = false;
		flag = 0;
	}

	string text;
	bool hover;
	int flag;

	bool block;

	void Hover(bool value) {
		hover = value;
	}

	bool is_hover() {
		return hover;
	}

	void Block() {
		block = true;
	}

	void Unlock() {
		block = false;
	}

	bool is_block() {
		return block;
	}
};

class DropDownList : public Control {
private:
	vector <DropDownItem*> List;
	SDL_Rect* item_sizes;

	bool show_list;

	int flag_select;
	int drop_type;

	SDL_Texture* image_drop_button;

	SDL_Surface* surface;
	SDL_Texture* destTexture;

public:

	DropDownList(SDL_Rect _sizes, SDL_Rect _itemSizes, int _drop_type, string _font, int _font_size, int _text_align) : Control(_sizes, "", _font, _font_size, _text_align)
	{
		drop_type = _drop_type;
		item_sizes = new SDL_Rect;
		*item_sizes = _itemSizes;
		flag_select = -1;
		show_list = false;

		
		image_drop_button = IMG_LoadTexture(renderer, "sfx/drop_button.png");
	};

	~DropDownList();

public:

	void render();

	DropDownItem* add(string text, int flag);

	void open(bool value);
	bool open();

	int checkItemHover(int x, int y);

	void setValue(string value);
	string getValue();

	int getFlag();
	const vector <DropDownItem*>* getItems();

	void clear();

	DropDownList* deleteItems();
};
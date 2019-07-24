#pragma once
#include "base_control.h"

struct Item {
	Item() {
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

class ItemList : public Control {
private:
	vector <Item*> List;
	SDL_Rect* item_sizes;
	bool show_list;

	SDL_Texture* image_drop_button;

public:
	ItemList(SDL_Rect _sizes, SDL_Rect _item_sizes, string _label, string _font, int _font_size, int _align_type) : Control(_sizes, _label, _font, _font_size, _align_type)
	{
		item_sizes = new SDL_Rect;
		*item_sizes = _item_sizes;

		show_list = false;

		image_drop_button = IMG_LoadTexture(renderer, "sfx/drop_button.png");
	};

	~ItemList();

public:
	void render();

	void add(string text, int flag);

	void open();
	void close();

	bool is_open();

	int checkItemHover(int x, int y);
};
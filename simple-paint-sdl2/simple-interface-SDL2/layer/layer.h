#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"

using namespace std;

class Layer
{
public:
	static int s_id;

public:
	SDL_BlendMode blend_mode;
	Uint8 alpha;
	SDL_Texture* texture;
	SDL_Rect size = { 0, 0, 0, 0 };

	int id;
	string name;

	bool display;
	bool blocked;


public:

	Layer(SDL_Texture* texture, string name, Uint8 alpha = 0xFF, 
		SDL_BlendMode blend_mode = SDL_BLENDMODE_BLEND)
	{
		if (name == "") this->name = "Layer " + s_id;
		else this->name = name;

		this->id = s_id;
		s_id++;


		this->alpha = alpha;
		this->texture = texture;
		this->blend_mode = blend_mode;

		SDL_QueryTexture(this->texture, NULL, NULL, &size.w, &size.h);

		this->display = true;
		this->blocked = false;
	}

	void set_alpha(Uint8 alpha);
	void set_blend_mode(SDL_BlendMode blend_mode);
	void block();
	void inlock();
	bool is_block();
	void show();
	void hide();
	bool is_display();

	void shift(int dx, int dy);
};

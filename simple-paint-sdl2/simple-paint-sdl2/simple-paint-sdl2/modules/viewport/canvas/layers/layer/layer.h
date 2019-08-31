#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "string"
using namespace std;

class Layer
{
public:
	static int s_id;

public:
	SDL_BlendMode blend_mode;
	Uint8 alpha;
	SDL_Texture* texture;
	SDL_Rect size;

	int id;
	string name;

	bool display;
	bool blocked;


public:
	Layer(SDL_Texture* texture, int id, string name, Uint8 alpha = 0xFF, SDL_BlendMode blend_mode = SDL_BLENDMODE_BLEND);

public:
	void set_alpha(Uint8 alpha);
	void set_blend_mode(SDL_BlendMode blend_mode);

	void block();
	void inlock();
	bool is_block();

	void show();
	void hide();
	bool is_show();

	void shift(int dx, int dy);
};

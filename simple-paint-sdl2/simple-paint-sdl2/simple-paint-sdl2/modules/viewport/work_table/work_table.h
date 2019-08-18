#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "iostream"
#include "../../colors/color.h"
#include "../../viewport/canvas/canvas.h"

using namespace std;

class WorkTable
{
private:
	SDL_Rect size;
	SDL_Texture* texture;

	Canvas* canvas;
	Viewport* parent;

public:
	WorkTable(Viewport* parent, );
	~WorkTable();


};

#pragma once

#include "SDL_ttf.h"
#include "iostream"
#include "../colors/color.h"
using namespace std;


struct Styles
{
	static const char* font_path;
	static const int font_size;

	static const string path_to_SystemExit;
	static const string path_to_SystemCollapse;
	static const string path_to_SystemExpand;
};
;
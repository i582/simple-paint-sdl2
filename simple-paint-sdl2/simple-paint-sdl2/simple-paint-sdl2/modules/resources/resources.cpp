#include "resources.h"


TTF_Font* Resources::font_verdana_12px = nullptr;
TTF_Font* Resources::font_verdana_11px = nullptr;

TTF_Font* Resources::font_lato_regular_25px = nullptr;
TTF_Font* Resources::font_lato_12px = nullptr;

SDL_Surface* Resources::texture_systemExit = nullptr;
SDL_Surface* Resources::texture_systemCollapse = nullptr;
SDL_Surface* Resources::texture_systemExpand = nullptr;

void Resources::init()
{
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError();
		return;
	}

	if (TTF_Init() == -1)
	{
		cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError();
		return;
	}

	Resources::font_verdana_12px = TTF_OpenFont("././resources/fonts/verdana.ttf", 12);
	Resources::font_verdana_11px = TTF_OpenFont("././resources/fonts/verdana.ttf", 11);

	Resources::font_lato_regular_25px = TTF_OpenFont("././resources/fonts/Lato-Light.ttf", 29);
	Resources::font_lato_12px = TTF_OpenFont("././resources/fonts/Lato-Regular.ttf", 12);

	Resources::texture_systemExit = IMG_Load("././resources/images/system_icon/exit.png");
	Resources::texture_systemCollapse = IMG_Load("././resources/images/system_icon/collapse.png");
	Resources::texture_systemExpand = IMG_Load("././resources/images/system_icon/expand.png");
}

void Resources::clear()
{		
	TTF_CloseFont(Resources::font_verdana_12px);
	TTF_CloseFont(Resources::font_verdana_11px);
	TTF_CloseFont(Resources::font_lato_regular_25px);
	TTF_CloseFont(Resources::font_lato_12px);

	SDL_FreeSurface(Resources::texture_systemExit);
	SDL_FreeSurface(Resources::texture_systemCollapse);
	SDL_FreeSurface(Resources::texture_systemExpand);
}

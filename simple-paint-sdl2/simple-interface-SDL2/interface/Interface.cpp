#include "Interface.h"

Interface::Interface()
{
	running = true;
	window = nullptr;
	renderer = nullptr;
	texture = nullptr;

	screenWidth = 1280;
	screenHeight = 720;

	count_ready = 0;
	count_element = 0;

	nowOperation = 0;

	ready_fill_classes = false;
}

Interface::Interface(short width, short height)
{
	running = true;
	window = nullptr;
	renderer = nullptr;
	texture = nullptr;

	screenWidth = width;
	screenHeight = height;

	count_ready = 0;
	count_element = 0;

	ready_fill_classes = false;
	nowOperation = 0;
}

Interface::~Interface()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	window = nullptr;
	renderer = nullptr;
	texture = nullptr;
	SDL_Quit();


	for (size_t i = 0; i < Buttons.size(); i++)
		delete Buttons.at(i);
	for (size_t i = 0; i < Inputs.size(); i++)
		delete Inputs.at(i);
	for (size_t i = 0; i < ItemLists.size(); i++)
		delete ItemLists.at(i);
	for (size_t i = 0; i < DropDownLists.size(); i++)
		delete DropDownLists.at(i);
	for (size_t i = 0; i < Labels.size(); i++)
		delete Labels.at(i);
	for (size_t i = 0; i < TextFields.size(); i++)
		delete TextFields.at(i);


	Buttons.clear();
	Inputs.clear();
	ItemLists.clear();
	DropDownLists.clear();
	Labels.clear();
	TextFields.clear();

	for (size_t i = 0; i < ptrBaseClass.size(); i++)
		delete ptrBaseClass.at(i);

	ptrBaseClass.clear();
	type_ptrBaseClasses.clear();

	TTF_Quit();
}

bool Interface::init()
{
	setlocale(LC_ALL, "Rus");

	if ((SDL_Init(SDL_INIT_EVERYTHING)) < 0) {
		cout << "Error of initialize SDL: " << SDL_GetError() << endl;
		return false;
	}

	if ((window = SDL_CreateWindow("Test string program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN )) == nullptr) {
		cout << "Error of initialize new Window: " << SDL_GetError() << endl;
		return false;
	}

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == nullptr) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	SDL_Rect win_sizes = { -1, -1, 200, 300 };
	Window* win = new Window("Window", &win_sizes, SDL_WINDOW_BORDERLESS , &Colors.background);
	win->init();
	//win->show();
	all_windows.push_back(win);

	win_sizes = { 200, 200, 500, 100 };
	Window* win1 = new Window("Window1", &win_sizes, SDL_WINDOW_BORDERLESS , &Colors.background);
	win1->init();
	//win1->show();
	all_windows.push_back(win1);

	tex = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 600, 500);

	return true;
}

void Interface::quit()
{
	running = false;
}


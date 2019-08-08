#include "editor.h"

Editor::Editor(int width, int height)
{
	this->running = true;

	SDL_Rect r = { -1, -1, width, height };
	this->main_window = new MainWindow("Editor", &r, NULL);
	this->main_window->render();
}

Editor::~Editor()
{
	if (main_window != nullptr)
		delete main_window;
}

bool Editor::init()
{
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) 
	{
		cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError();
		return false;
	}

	if (TTF_Init() == -1) 
	{
		cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError();
		return false;
	}

	return true;
}

void Editor::setup()
{
	main_window->show();
}

void Editor::update()
{
	main_window->render();
}

void Editor::quit()
{
	running = false;
}

int Editor::onExecute()
{
	if (!init())
		return -1;

	setup();
	update();
	onEvent();

	return 0;
}

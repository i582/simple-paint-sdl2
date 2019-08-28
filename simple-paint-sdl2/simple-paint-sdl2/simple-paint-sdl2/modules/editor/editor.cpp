#include "editor.h"


Event* Editor::push_event(Event* ev)
{
	if (ev == nullptr)
		throw "Error event (nullptr)";

	events.push_back(ev);
	return ev;
}

Editor::Editor(int width, int height)
{
	this->running = true;

	SDL_Rect r = { -1, -1, width, height };
	this->main_window = new MainWindow("NIA Editor", &r, SDL_WINDOW_BORDERLESS);
	
	this->main_window->render();
	this->selected_tool = 1;
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

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"))
	{
		cout << "Error set hint" << endl;
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1"))
	{
		cout << "Error set hint" << endl;
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

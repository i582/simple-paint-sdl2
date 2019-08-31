#include "editor.h"

Editor* Editor::instance = nullptr;

Editor* Editor::get_instance()
{
	if (instance == nullptr)
		instance = new Editor(1350, 700);

	return instance;
}

Event* Editor::push_event(Event* ev)
{
	if (ev == nullptr)
		throw "Error event (nullptr)";

	events.push_back(ev);
	return ev;
}

Editor::Editor(int width, int height)
{
	this->main_window = nullptr;
	this->new_document = nullptr;
	this->e = {};
	this->running = true;
	this->width = width;
	this->height = height;
	this->selected_tool = 1;
}

Editor::~Editor()
{
	if (main_window != nullptr)
		delete main_window;

	Resources::clear();
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

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"))
	{
		cout << "Error set hint" << endl;
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1"))
	{
		cout << "Error set hint" << endl;
		return false;
	}

	Resources::init();

	return true;
}

void Editor::setup()
{
	SDL_Rect r2 = { -1, -1, 800, 480 };
	this->new_document = new NewDocumentWindow("New document", &r2, SDL_WINDOW_BORDERLESS);


	SDL_Rect r = { -1, -1, width, height };
	this->main_window = new MainWindow("NIA Editor", &r, SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS);
}

void Editor::update()
{
	/*if (main_window->is_show())
		main_window->render();*/
}

void Editor::quit()
{
	running = false;
}

int Editor::run()
{
	if (!init())
		return -1;

	setup();
	update();
	onEvent();

	return 0;
}

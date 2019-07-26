#include "editor.h"

Editor::Editor(int width, int height)
{
	this->running = true;
	SDL_Rect r = { -1, -1, width, height };
	this->window = new Window("Editor", &r, NULL, &Colors::background);
	this->window->init();
}

Editor::~Editor()
{
	if (window != nullptr)
		delete window;
}

bool Editor::init()
{
	setlocale(LC_ALL, "Rus");

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError();
		return false;
	}

	if (TTF_Init() == -1) {
		cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError();
		return false;
	}

	return true;
}

void Editor::setup()
{
	window->update();
	window->show();
}

void Editor::update()
{
	window->update();


	/*viewport = new Viewport(window->getRenderer(), 20, 20, 1000, 660);
	canvas = new Canvas(window->getRenderer(), viewport->get_render_target(), 100, 100, 500, 500);
	viewport->set_canvas(canvas);*/
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

#include "main-window.h"

MainWindow::MainWindow(string title, SDL_Rect* sizes, Uint32 flags) : Window(title, sizes, flags)
{
	init();
}

bool MainWindow::init()
{
	if ((window = SDL_CreateWindow(title.c_str(), x == -1 ? SDL_WINDOWPOS_CENTERED : x, y == -1 ? SDL_WINDOWPOS_CENTERED : y, width, height, flags | SDL_WINDOW_HIDDEN)) == nullptr) {
		cout << "Error of initialize new Window: " << SDL_GetError() << endl;
		return false;
	}

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == nullptr) {
		cout << "Renderer could not be created! SDL Error: %s\n" << SDL_GetError();
		return false;
	}

	setup();

	return true;
}

void MainWindow::setup()
{
	show();

	viewport = new Viewport(renderer, 20, 20, 1000, 660);
	canvas = new Canvas(renderer, viewport->get_render_target(), 100, 100, 500, 500);
	viewport->set_canvas(canvas);

}

void MainWindow::render()
{
	SDL_SetDrawColor(renderer, Colors::background);
	SDL_RenderFillRect(renderer, NULL);

	viewport->update();

	update();
}
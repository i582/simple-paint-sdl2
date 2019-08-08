#include "main-window.h"

MainWindow::MainWindow(string title, SDL_Rect* sizes, Uint32 flags) : Window(title, sizes, flags)
{
	init();
}

void MainWindow::setup()
{
	show();

	viewport = new Viewport(renderer, 50, 30, 1000, 640);
	canvas = new Canvas(renderer, viewport, 100, 100, 1000, 1000);

	layer_viewer = new LayerViewer(renderer, { 1052, 470, 295, 201 }, canvas->get_layers());
	viewport->set_layer_viewer(layer_viewer);

	viewport->set_canvas(canvas);

	
	toolbar = new Toolbar(renderer, { 0, 30, 40, 640 });

}

void MainWindow::render()
{
	SDL_SetDrawColor(renderer, Colors::background);
	SDL_RenderFillRect(renderer, NULL);

	layer_viewer->update();

	viewport->update();

	toolbar->update();

	SDL_RenderPresent(renderer);
}

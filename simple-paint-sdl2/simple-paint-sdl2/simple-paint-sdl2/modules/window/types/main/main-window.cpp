#include "main-window.h"

MainWindow::MainWindow(string title, SDL_Rect* sizes, Uint32 flags) : Window(title, sizes, flags)
{
	init();
}

void MainWindow::setup()
{
	show();

	viewport = new Viewport(renderer, 50, 30, 1000, 640);

	layers_viewer = new LayersViewer(renderer, viewport, { 1052, 470, 295, 201 });
	
	viewport->set_layer_viewer(layers_viewer);




	toolbar = new Toolbar(renderer, { 0, 30, 40, 640 });

	container = new Container(renderer, { 1100, 30, 200, 200 });

}

void MainWindow::render()
{
	SDL_SetDrawColor(renderer, Colors::background);
	SDL_RenderFillRect(renderer, NULL);

	layers_viewer->update();

	viewport->update();

	toolbar->update();

	container->update();

	SDL_RenderPresent(renderer);
}

void MainWindow::resized()
{
	viewport->set_size((int)(width * 0.74), (int)(height * 0.914));
	viewport->init();
	viewport->setup_scrolls();
	//viewport->get_canvas()->center_align();
	render();
}

void MainWindow::set_size(int width, int height)
{
	this->width = width;
	this->height = height;
}

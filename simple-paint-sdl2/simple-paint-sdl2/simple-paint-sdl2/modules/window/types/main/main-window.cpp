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

	// must be last
	viewport->set_canvas(canvas);

	Tool* tool1 = new Tool(renderer, 5, 5);
	Tool* tool2 = new Tool(renderer, 5, 35);
	Tool* tool3 = new Tool(renderer, 5, 65);

	tools.push_back(tool1);
	tools.push_back(tool2);
	tools.push_back(tool3);

}

void MainWindow::render()
{
	SDL_SetDrawColor(renderer, Colors::background);
	SDL_RenderFillRect(renderer, NULL);

	layer_viewer->update();

	viewport->update();

	for (auto& tool : tools)
	{
		tool->render();
	}

	SDL_RenderPresent(renderer);
}

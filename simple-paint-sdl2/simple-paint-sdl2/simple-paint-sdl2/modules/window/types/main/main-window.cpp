#include "main-window.h"

DropWindow* MainWindow::drop_window = nullptr;

MainWindow::MainWindow(string title, SDL_Rect* sizes, Uint32 flags) 
	: Window(title, sizes, flags)
{
	init();
}

void MainWindow::update()
{

	for (int i = controls.size() - 1; i >= 0; i--)
	{
		controls.at(i)->update();
	}

}


SDL_HitTestResult MainWindow::HitTest(SDL_Window* wind, const SDL_Point* area, void* data)
{
	if (SDL_PointInRect(area, ((SDL_Rect*)data)))
		return SDL_HITTEST_DRAGGABLE;

	return SDL_HITTEST_NORMAL;
}


void MainWindow::setup()
{
	SDL_Rect* r = new SDL_Rect;
	*r = { 0, 0, width - 150, 35 };
	SDL_SetWindowHitTest(window, HitTest, r);


	icon_texture = IMG_LoadTexture(renderer, "././././resources/images/icon.png");

	show();

	viewport = new Viewport(renderer, 50, 35, 1000, 660);
	canvas = new Canvas(renderer, viewport, 100, 100, 1000, 1000);

	layers_viewer = new LayersViewer(renderer, viewport, { 1052, 495, 295, 201 }, canvas->get_layers());
	viewport->set_layer_viewer(layers_viewer);

	viewport->set_canvas(canvas);

	
	toolbar = new Toolbar(renderer, { 1, 30, 40, 640 });
	menubar = new MenuBar(this, { 0, 0, width, 0 }, 15);

	dropdown = new DropDownList(this, NULL, "drop", 100, { 1200, 100, 100, 20 });



	CreateControl(new Button(this, NULL, 123, "Save", { 1100, 50, 60, 25 }));
	CreateControl(new Button(this, NULL, 124, "Create", { 1100, 80, 60, 25 }));
	CreateControl(new Button(this, NULL, 125, "New", { 1100, 110, 60, 25 }));

	CreateControl(new Checkbox(renderer, NULL, 126, { 1200, 50 , 16, 16 }));

	CreateControl(new RadioButton(this, NULL, 1, 126, { 1250, 50 , 16, 16 }));

	CreateControl(new ButtonImg(this, NULL, SYSTEM_EXIT, "", { width - 51, 1, 49, 34 }, Styles::path_to_SystemExit));
	CreateControl(new ButtonImg(this, NULL, SYSTEM_EXPAND, "", { width - 101, 1, 49, 34 }, Styles::path_to_SystemExpand));
	CreateControl(new ButtonImg(this, NULL, SYSTEM_COLLAPSE, "", { width - 151, 1, 49, 34 }, Styles::path_to_SystemCollapse));

	SDL_Rect r1 = { -1, -1, 300, 300 };
	MainWindow::drop_window = new DropWindow("", &r1, SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FOREIGN);




	

}


void MainWindow::render()
{
	SDL_SetDrawColor(renderer, Colors::background);
	SDL_RenderFillRect(renderer, NULL);

	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(back, SDL_BLENDMODE_BLEND);


	SDL_RenderCopy(renderer, back, NULL, NULL);

	layers_viewer->update();

	viewport->update();

	toolbar->update();

	menubar->update();

	dropdown->update();

	update();

	SDL_Rect i_r = { 2, 0, 35, 35 };
	SDL_RenderCopy(renderer, icon_texture, NULL, &i_r);

	SDL_SetRenderDrawColor(renderer, 0xc9, 0x50, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, NULL);

	SDL_RenderPresent(renderer);
}

void MainWindow::resized()
{
	viewport->set_size((int)(width * 0.74), (int)(height * 0.914));
	viewport->init();
	viewport->setup_scrolls();
	viewport->get_canvas()->center_align();
	render();
}

void MainWindow::set_size(int width, int height)
{
	this->width = width;
	this->height = height;
}

Control* const MainWindow::CreateControl(Control* el)
{
	controls.push_back(el);
	return el;
}

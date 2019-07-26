#include "window.h"

Window::Window(string title, SDL_Rect* sizes, Uint32 flags)
{
	this->title = title;

	this->width = sizes->w;
	this->height = sizes->h;

	this->x = sizes->x;
	this->y = sizes->y;

	this->flags = flags;

	this->no_border = flags & 0x00000010;

	this->background_color = Colors::element_background;

	window = nullptr;
	renderer = nullptr;

	hover_close = false;
	close_button_coord = { width - 20, 1, 19, 14 };
}

Window::Window(string title, SDL_Rect* sizes, Uint32 flags, SDL_Color* background_color)
{
	this->title = title;

	this->width = sizes->w;
	this->height = sizes->h;

	this->x = sizes->x;
	this->y = sizes->y;

	this->flags = flags;
	this->no_border = flags & 0x00000010;

	this->background_color = *background_color;

	window = nullptr;
	renderer = nullptr;

	hover_close = false;
	close_button_coord = { width - 20, 1, 19, 14 };
}

Window::~Window()
{
	if (window != nullptr)
		SDL_DestroyWindow(window);
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);
}

void Window::render()
{
	if (no_border) 
	{

		SDL_SetDrawColor(renderer, Colors::background);
		SDL_RenderFillRect(renderer, NULL);

		SDL_SetDrawColor(renderer, Colors::element_border);
		SDL_RenderDrawRect(renderer, NULL);

		render_toolup();
	}
	else {
		SDL_SetDrawColor(renderer, background_color);
		SDL_RenderFillRect(renderer, NULL);
	}

	SDL_RenderPresent(renderer);
}

void Window::render_toolup()
{
	SDL_Rect up_tool = { 0, 0, width, 15 };
	SDL_SetDrawColor(renderer, Colors::element_border);
	SDL_RenderDrawLine(renderer, up_tool.x, up_tool.h, up_tool.w, up_tool.h);

	SDL_Texture* icon_close = IMG_LoadTexture(renderer, "sfx/icon_close.png");
	int icon_close_width;
	int icon_close_height;
	SDL_QueryTexture(icon_close, NULL, NULL, &icon_close_width, &icon_close_height);
	SDL_Rect but_close_position = { width - 13, 5, icon_close_width, icon_close_height };

	if (hover_close)
		SDL_SetDrawColor(renderer, Colors::element_background_focus);
	else
		SDL_SetDrawColor(renderer, Colors::background);

	SDL_RenderFillRect(renderer, &close_button_coord);

	SDL_SetDrawColor(renderer, Colors::element_border);
	SDL_RenderDrawLine(renderer, close_button_coord.x, 0, close_button_coord.x, close_button_coord.h);

	SDL_RenderCopy(renderer, icon_close, NULL, &but_close_position);
	SDL_RenderPresent(renderer);

	SDL_DestroyTexture(icon_close);
}

int Window::SDL_WindowHitTest(SDL_Window* win, void* callback_data)
{
	return SDL_SetWindowHitTest(win,
		[](SDL_Window * win, const SDL_Point * area, void* callback_data) -> SDL_HitTestResult {
			SDL_Rect rec = { 0, 0, 180, 15 };
			if (SDL_PointInRect(area, &rec))
				return SDL_HITTEST_DRAGGABLE;
			
			return SDL_HITTEST_NORMAL;
		}
	, callback_data);
}

int Window::SDL_SetDrawColor(SDL_Renderer* renderer, SDL_Color color)
{
	return SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

bool Window::init()
{
	if ((window = SDL_CreateWindow(title.c_str(), x == -1 ? SDL_WINDOWPOS_CENTERED : x, y == -1 ? SDL_WINDOWPOS_CENTERED : y, width, height, flags | SDL_WINDOW_HIDDEN)) == nullptr) {
		cout << "Error of initialize new Window: " << SDL_GetError() << endl;
		return false;
	}

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == nullptr) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_WindowHitTest(window, NULL);
	
	return true;
}

void Window::show()
{
	SDL_ShowWindow(window);
	render();
}

void Window::hide()
{
	SDL_HideWindow(window);
	render();
}

void Window::close()
{
	SDL_DestroyWindow(window);
}

void Window::update()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}

void Window::mouseButtonDown(SDL_Event* event)
{

}

void Window::mouseButtonUp(SDL_Event* event)
{

	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (SDL_PointInRect(&mouse_coord, &close_button_coord)) {
		SDL_DestroyWindow(window);
	}
}

void Window::mouseMotion(SDL_Event* event)
{
	
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	/*hover_close = SDL_PointInRect(&mouse_coord, &close_button_coord);
	render_toolup();*/
}

void Window::mouseWheel(SDL_Event* event)
{
}

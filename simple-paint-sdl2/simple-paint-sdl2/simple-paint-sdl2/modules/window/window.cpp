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

	this->window = nullptr;
	this->renderer = nullptr;

	this->hover_close = false;
	this->close_button_coord = { width - 20, 1, 19, 14 };

	this->mouse_coord = { 0, 0 };
}

Window::~Window()
{
	if (window != nullptr)
		SDL_DestroyWindow(window);
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);
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
		cout << "Renderer could not be created! SDL Error: %s\n" << SDL_GetError();
		return false;
	}

	setup();
	
	return true;
}

void Window::show()
{
	SDL_ShowWindow(window);
}

void Window::hide()
{
	SDL_HideWindow(window);
}

void Window::close()
{
	SDL_DestroyWindow(window);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}

#include "window.h"

//#include "windows.h"
#include "SDL_syswm.h"

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

	this->display = false;

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
	if ((window = SDL_CreateWindow(title.c_str(), x == -1 ? SDL_WINDOWPOS_CENTERED : x, y == -1 ? SDL_WINDOWPOS_CENTERED : y, width, height, flags)) == nullptr) {
		cout << "Error of initialize new Window: " << SDL_GetError() << endl;
		return false;
	}


	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC)) == nullptr) {
		cout << "Renderer could not be created! SDL Error: %s\n" << SDL_GetError();
		return false;
	}

	SDL_SetWindowIcon(window, IMG_Load("/Users/petrmakhnev/CLionProjects/paint-sdl2/resources/images/icon_1.png"));

	setup();
	
	SDL_GetWindowPosition(window, &x, &y);

	return true;
}

void Window::show()
{
	display = true;
	SDL_ShowWindow(window);
}

void Window::hide()
{
	display = false;
	SDL_HideWindow(window);
}

bool Window::is_show()
{
	return display;
}

void Window::close()
{
	SDL_DestroyWindow(window);
}

void Window::set_position(int x, int y)
{
	SDL_SetWindowPosition(window, x, y);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}

SDL_Window* Window::get_window()
{
	return window;
}

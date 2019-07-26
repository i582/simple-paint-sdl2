#include "editor.h"

void Editor::onEvent()
{
	while (running && SDL_WaitEvent(&event)) 
	{

		switch (event.type)
		{

		case SDL_MOUSEMOTION:
		{
			main_window->mouseMotion(&event);
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			main_window->mouseButtonDown(&event);
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			main_window->mouseButtonUp(&event);
			break;
		}

		case SDL_MOUSEWHEEL:
		{
			main_window->mouseWheel(&event);
			break;
		}

		case SDL_KEYDOWN:
		{
			main_window->keyDown(&event);
			break;
		}

		case SDL_KEYUP:
		{
			main_window->keyUp(&event);
			break;
		}

		case SDL_QUIT: 
		{
			quit();
			break;
		}

		default:break;
		}
	}
}
#include "editor.h"

void Editor::onEvent()
{
	while (running && SDL_WaitEvent(&event)) 
	{

		switch (event.type)
		{

		case SDL_MOUSEMOTION:
		{
			window->mouseMotion(&event);
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			window->mouseButtonDown(&event);
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			window->mouseButtonUp(&event);
			break;
		}

		case SDL_MOUSEWHEEL:
		{
			window->mouseWheel(&event);
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
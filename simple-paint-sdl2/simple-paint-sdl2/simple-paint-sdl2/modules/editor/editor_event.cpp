#include "editor.h"

void Editor::onEvent()
{
	while (running && SDL_WaitEvent(&e)) 
	{

		switch (e.type)
		{

		case SDL_MOUSEMOTION:
		{
			main_window->mouseMotion(&e);
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			main_window->mouseButtonDown(&e);
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			main_window->mouseButtonUp(&e);
			break;
		}

		case SDL_MOUSEWHEEL:
		{
			main_window->mouseWheel(&e);
			break;
		}

		case SDL_KEYDOWN:
		{
			main_window->keyDown(&e);
			break;
		}

		case SDL_KEYUP:
		{
			main_window->keyUp(&e);
			break;
		}

		case SDL_QUIT: 
		{
			quit();
			break;
		}

		case SDL_WINDOWEVENT:
		{

			switch (e.window.event)
			{

			case SDL_WINDOWEVENT_RESIZED:
			{
				main_window->render();
				break;
			}

			default:break;
			}

			break;
		}

		default:break;
		}
	}
}
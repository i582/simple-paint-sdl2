#include "editor.h"
#include "ctime"
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
				//main_window->render();
				cout << "SDL_WINDOWEVENT_RESIZED" << endl;
				break;
			}

			case SDL_WINDOWEVENT_SIZE_CHANGED:
			{
				cout << "SDL_WINDOWEVENT_SIZE_CHANGED" << endl;

				main_window->set_size(e.window.data1, e.window.data2);
				
				main_window->resized();

			
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
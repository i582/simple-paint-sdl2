#include "editor.h"

void Editor::onEvent()
{
	while (running && SDL_WaitEvent(&e)) 
	{
		
		switch (e.window.windowID)
		{


		case WINDOW_NEW_DOCUMENT:
		{
			switch (e.type)
			{

			case SDL_MOUSEMOTION:
			{
				new_document->mouseMotion(&e);
				break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
				new_document->mouseButtonDown(&e);
				break;
			}

			case SDL_MOUSEBUTTONUP:
			{
				new_document->mouseButtonUp(&e);
				break;
			}

			case SDL_MOUSEWHEEL:
			{
				new_document->mouseWheel(&e);
				break;
			}

			case SDL_KEYDOWN:
			{
				new_document->keyDown(&e);
				break;
			}

			case SDL_KEYUP:
			{
				new_document->keyUp(&e);
				break;
			}

			case SDL_TEXTINPUT:
			{
				new_document->textInput(&e);
				break;
			}

			case SDL_QUIT:
			{
				new_document->close();
				break;
			}

			}

			break;
		}



		case WINDOW_MAIN:
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

			case SDL_TEXTINPUT:
			{
				main_window->textInput(&e);
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

				case SDL_WINDOWEVENT_ENTER:
				{
					

					break;
				}

				case SDL_WINDOWEVENT_RESIZED:
				{
					//main_window->render();
					cout << "SDL_WINDOWEVENT_RESIZED" << endl;
					break;
				}

				case SDL_WINDOWEVENT_SIZE_CHANGED:
				{
					cout << "SDL_WINDOWEVENT_SIZE_CHANGED" << endl;

					//main_window->set_size(e.window.data1, e.window.data2);

					//main_window->resized();


					break;
				}

				default:break;
				}

				break;
			}

			default:break;
			}

			break;
		}

		default:
			
			break;
		}

	
		sendHandleUserEvent();

	}
}

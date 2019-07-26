#include "interface.h"

void Interface::onEvent()
{
	while (running) {
		while (SDL_WaitEvent(&event)) {

			switch (event.type)
			{

			case SDL_MOUSEMOTION: 
			{
				SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

				if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) {
					viewport->mouseMotion(&event);
	
				}

				mouseMotion(&event);

				if (event.window.windowID > 1) {
					int id = event.window.windowID - 2;
					all_windows.at(id)->mouseMotion(&event);
				}
				break;
			}

			case SDL_MOUSEBUTTONDOWN: 
			{
				SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

				if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) {
					viewport->mouseButtonDown(&event);
					
				}

				mouseButtonDown(&event);

				if (event.window.windowID > 1) {
					int id = event.window.windowID - 2;
					all_windows.at(id)->mouseButtonDown(&event);
				}
				break;
			}

			case SDL_MOUSEBUTTONUP: 
			{
				SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

				if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) {
					viewport->mouseButtonUp(&event);
					
				}

				mouseButtonUp(&event);

				if (event.window.windowID > 1) {
					int id = event.window.windowID - 2;
					all_windows.at(id)->mouseButtonUp(&event);
				}

				break;
			}

			case SDL_MOUSEWHEEL: 
			{

				if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) {
					viewport->mouseWheel(&event);

				}
				break;
			}

			case SDL_QUIT:
				quit();
				break;

			default:break;
			}
		}
	}
}

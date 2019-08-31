#include "editor.h"

vector <Event*> Editor::events = {};

void Editor::sendHandleUserEvent()
{

	while (events.size())
	{
		Event* ev = events.front();
		events.pop_back();

		switch (e.window.windowID)
		{

		case WINDOW_NEW_DOCUMENT:
		{

			if (ev->common.object_id == SYSTEM_EXIT &&
				ev->common.action == BUTTON_RELEASED)
			{
				quit();
				return;
			}



			new_document->handleUserEvents(ev);

			break;
		}



		case WINDOW_MAIN:
		{

			if (ev->common.object_id == SYSTEM_EXIT &&
				ev->common.action == BUTTON_RELEASED)
			{
				quit();
				return;
			}

	
			main_window->handleUserEvents(ev);

			break;
		}

		default:
			throw "Error unhandled window with";
			break;
		}
	}
}
#include "editor.h"

vector <Event*> Editor::events = {};

void Editor::sendHandleUserEvent()
{

	while (events.size())
	{
		Event* ev = events.front();
		events.pop_back();

		

		switch (ev->common.object_id)
		{

		case SYSTEM_EXIT:
		{
			switch (ev->common.action)
			{

			case BUTTON_RELEASED:
			{
				quit();
				break;
			}

			default:break;
			}

			break;
		}
		

		default:
			main_window->handleUserEvents(ev);
			break;
		}

	}

}
#include "main-window.h"

void MainWindow::handleUserEvents(Event* ev)
{

	switch (ev->common.object_id)
	{

	case SYSTEM_COLLAPSE:
	{

		switch (ev->common.action)
		{

		case BUTTON_RELEASED:
		{
			SDL_MinimizeWindow(window);
			break;
		}

		default:break;
		}

		break;


	case SYSTEM_EXPAND:
	{

		break;
	}

	default:break;
	}
	}


	switch (ev->common.caller)
	{

	case BUTTON:
	{
		//cout << "1" << endl;

		switch (ev->common.action)
		{
		case BUTTON_PRESSED:
		{
			cout << ev->common.object_id << " pressed" << endl;

			break;
		}

		case BUTTON_RELEASED:
		{
			cout << ev->common.object_id << " released" << endl;

			break;
		}

		default:break;
		}

		break;
	}

	case CHECKBOX:
	{

		switch (ev->common.action)
		{

		case CHECKBOX_CHECKED:
		{
			cout << "checkbox checked" << ev->common.object_id << endl;
			break;
		}

		case CHECKBOX_UNCHECKED:
		{
			cout << "checkbox unchecked" << ev->common.object_id << endl;
			break;
		}

		default: break;
		}

		break;
	}

	default:break;
	}

}

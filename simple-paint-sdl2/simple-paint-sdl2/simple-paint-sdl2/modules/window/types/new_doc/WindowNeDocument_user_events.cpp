#include "WindowNewDocument.h"
#include "../../../editor/editor.h"

void NewDocumentWindow::handleUserEvents(Event* ev)
{

	switch (ev->common.caller)
	{

	case BUTTON:
	{


		if (ev->common.object_id == BUTTON_CREATE &&
			ev->common.action == BUTTON_RELEASED)
		{
			int width = atoi(controls.at(INPUT_WIDTH)->get_value().c_str());
			int height = atoi(controls.at(INPUT_HEIGHT)->get_value().c_str());

			cout << width << "  " << height << endl;

			Editor::get_instance()->main_window->setup_canvas({ 0, 0, width, height });

			this->hide();
		}

	
		break;
	}

	}

}

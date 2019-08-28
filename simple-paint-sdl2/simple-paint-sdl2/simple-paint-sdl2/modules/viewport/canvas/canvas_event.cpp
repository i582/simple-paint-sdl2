#include "canvas.h"
#include "../viewport.h"
#include "../../editor/editor.h"

void Canvas::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord_with_scale(&pos_mouse.x, &pos_mouse.y);

	is_selected = true;
	selected_id = layers->get_upper_layer_id_in_point(pos_mouse.x, pos_mouse.y);
}

void Canvas::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord_with_scale(&pos_mouse.x, &pos_mouse.y);


	is_selected = false;
}

void Canvas::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord_with_scale(&pos_mouse.x, &pos_mouse.y);

	if (is_selected && selected_id != -1)
	{
		layers->at(selected_id)->shift(
			(int)(e->motion.xrel / get_size_factor()),
			(int)(e->motion.yrel / get_size_factor())
		);

		//Editor::push_event(new Event(BUTTON, BUTTON_PRESSED, 10));

		update();
	}
}

void Canvas::keyDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord_with_scale(&pos_mouse.x, &pos_mouse.y);


}

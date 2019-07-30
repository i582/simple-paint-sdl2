#include "canvas.h"
#include "../viewport/viewport.h"

void Canvas::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	parent->update_coord(&pos_mouse.x, &pos_mouse.y);
	update_coord_with_scale(&pos_mouse.x, &pos_mouse.y);

	is_selected = true;
	selected_id = layers->get_upper_layer_id();
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

	if (is_selected)
	{
		layers->at(selected_id)->shift(e->motion.xrel, e->motion.yrel);
		update();
	}
}

void Canvas::keyDown(SDL_Event* e)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord_with_scale(&pos_mouse.x, &pos_mouse.y);


}

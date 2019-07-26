#include "canvas.h"

void Canvas::mouseButtonDown(SDL_Event* event, SDL_Point _pos_mouse)
{
	pos_mouse = _pos_mouse;
	update_coord(&this->pos_mouse.x, &this->pos_mouse.y);


}

void Canvas::mouseButtonUp(SDL_Event* event, SDL_Point _pos_mouse)
{
	pos_mouse = _pos_mouse;
	update_coord(&pos_mouse.x, &pos_mouse.y);


}

void Canvas::mouseMotion(SDL_Event* event, SDL_Point _pos_mouse)
{
	pos_mouse = _pos_mouse;
	update_coord(&pos_mouse.x, &pos_mouse.y);


}

void Canvas::keyDown(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


}

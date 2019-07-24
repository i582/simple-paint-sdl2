#include "viewport.h"

void Viewport::mouseButtonDown(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);


}

void Viewport::mouseButtonUp(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	
}

void Viewport::mouseMotion(SDL_Event* event)
{
	SDL_GetMouseState(&pos_mouse.x, &pos_mouse.y);
	update_coord(&pos_mouse.x, &pos_mouse.y);

	
}

void Viewport::keyDown(SDL_Event* event)
{
}

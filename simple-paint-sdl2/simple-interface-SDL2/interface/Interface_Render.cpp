#include "interface.h"

void Interface::render()
{
	
	SDL_SetRenderDrawColor(renderer, Colors::canvas_background.r, Colors::canvas_background.g, Colors::canvas_background.b, Colors::canvas_background.a);
	SDL_RenderFillRect(renderer, NULL);

	SDL_RenderPresent(renderer);


	for (size_t i = 0; i < Buttons.size(); i++)
		Buttons.at(i)->render();

	for (size_t i = 0; i < ItemLists.size(); i++)
		ItemLists.at(i)->render();

	for (size_t i = 0; i < Labels.size(); i++)
		Labels.at(i)->render();

	for (size_t i = 0; i < TextFields.size(); i++)
		TextFields.at(i)->render();

	for (size_t i = 0; i < Inputs.size(); i++)
		Inputs.at(i)->render();

	for (size_t i = 0; i < DropDownLists.size(); i++)
		DropDownLists.at(i)->render();

	
	


	viewport = new Viewport(renderer, 20, 20, 1000, 660);
	canvas = new Canvas(renderer, viewport->get_render_target(), 100, 100, 500, 500);
	
	viewport->set_canvas(canvas);
}

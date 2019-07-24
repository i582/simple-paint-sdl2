#include "interface.h"

void Interface::render()
{
	
	SDL_SetRenderDrawColor(renderer, Colors.canvas_background.r, Colors.canvas_background.g, Colors.canvas_background.b, Colors.canvas_background.a);
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

	
	
	
	/*SDL_SetRenderTarget(renderer, tex);
	SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.canvas_background.a);
	SDL_RenderFillRect(renderer, NULL);

	SDL_RenderPresent(renderer);


	Primitives::renderer = renderer;
	Primitives::color = &Colors.element_border_click;
	Primitives::tex = tex;
*/
	//Primitives::line(500, 0, 200, 400);
	//Primitives::line(500, 0, 200, 100);
	//Primitives::line(0, 0, 200, 400);
	////Primitives::line(200, 100, 100, 450);
	//Primitives::line(200, 100, 100, 450);

	//Primitives::line(0, 0, 100, 100);
	//Primitives::line(100, 100, 400, 300);


	//SDL_Point x11 = { 20, 20 };
	//SDL_Point x12 = { 220, 25 };

	//Primitives::line(&x11, &x12);

	//Primitives::circle(100, 100, 50);
	//Primitives::fill(100, 100);
	/*Primitives::h_line(100, 300, 300, 65);

	Primitives::v_line(400, 100, 500, 5);*/


	//Primitives::line(0, 0, 200, 400);
	//Primitives::line(500, 200, 200, 400, 50);

	//Primitives::line(500, 400, 200, 100, 50);
	//Primitives::line(100, 400, 300, 100, 50);

	//Primitives::line(100, 100, 300, 300, 50);
	//Primitives::circle(200, 200, 50);
	//Primitives::fill(201, 200, tex);
	//Primitives::fill(10, 20, tex);
	//Primitives::fill_circle(200, 200, 50);
	

	/*SDL_SetRenderTarget(renderer, NULL);
	SDL_Rect ren_rec = { 0, 0, 600, 500 };
	SDL_RenderCopy(renderer, tex, NULL, &ren_rec);
	SDL_RenderPresent(renderer);*/

	viewport = new Viewport(renderer, 1000, 660, 20, 20);
	viewport->init();
	viewport->update();
}

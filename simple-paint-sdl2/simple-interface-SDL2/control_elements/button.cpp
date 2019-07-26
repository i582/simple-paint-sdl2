#include "button.h"

void Button::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w += 2;
		clearRect.h += 2;

		SDL_SetRenderColor(renderer, Colors::background);
		SDL_RenderFillRect(renderer, &clearRect);
		SDL_RenderPresent(renderer);
		return;
	}

	SDL_Rect border = *sizes;
	border.x--;
	border.y--;
	border.w += 2;
	border.h += 2;

	if (click && !block)
		SDL_SetRenderColor(renderer, Colors::element_border_click);
	else
		SDL_SetRenderColor(renderer, Colors::element_border);
		
	SDL_RenderFillRect(renderer, &border);


	if (block)
		SDL_SetRenderColor(renderer, Colors::element_blocked);
	else
		if (click)
			SDL_SetRenderColor(renderer, Colors::element_background_click);
		else
			SDL_SetRenderColor(renderer, Colors::element_background);

	SDL_RenderFillRect(renderer, sizes);

	renderLabel(label, sizes);
	SDL_RenderPresent(renderer);
}
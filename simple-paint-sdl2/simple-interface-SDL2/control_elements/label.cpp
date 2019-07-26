#include "label.h"

void Label::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w = 160; // спорный момент, установите в средний размер элемента над которым эта надпись есть
		clearRect.h += 2;

		SDL_SetRenderColor(renderer, Colors.background);
		SDL_RenderFillRect(renderer, sizes);
		SDL_RenderPresent(renderer);
		return;
	}

	renderLabel(label, sizes);
	SDL_RenderPresent(renderer);
}

void Label::set_text(string text)
{
	label = text;
}

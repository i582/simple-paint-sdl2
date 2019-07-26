#include "textField.h"

void TextField::add(string newLine)
{
	if (lines.size() < 30) {
		lines.push_back(newLine);
	}
	else {
		auto iter = lines.cbegin();
		lines.erase(iter);
		lines.push_back(newLine);
	}

	render();
}

void TextField::render()
{
	SDL_SetRenderColor(renderer, Colors::element_background);
	SDL_RenderFillRect(renderer, sizes);

	SDL_Rect rect = { sizes->x + 5, sizes->y + 10, sizes->w - 10, 15 };

	for (size_t i = 0; i < lines.size(); i++)
	{
		renderLabel(lines.at(i), &rect);
		rect.y += 16;
	}

	SDL_RenderPresent(renderer);
}
#include "input.h"

void Input::render()
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

	if (focus && !block)
		SDL_SetRenderColor(renderer, Colors::element_border_click);
	else
		SDL_SetRenderColor(renderer, Colors::element_border);

	SDL_RenderFillRect(renderer, &border);



	if (block)
		SDL_SetRenderColor(renderer, Colors::element_blocked);
	else
		if (focus)
			SDL_SetRenderColor(renderer, Colors::element_background_focus);
		else
			SDL_SetRenderColor(renderer, Colors::element_background_unfocus);
	
	
	SDL_RenderFillRect(renderer, sizes);

	renderLabel(label, sizes);
	SDL_RenderPresent(renderer);
}

void Input::onEvent(SDL_Event* e)
{
	SDL_StartTextInput();
	while (focus) {
		while (SDL_PollEvent(e)) {
			switch (e->type)
			{

			case SDL_KEYDOWN:
			{
				if (e->key.keysym.sym == SDLK_BACKSPACE && label.length() > 0)
					label.pop_back();
				else if (e->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
					SDL_SetClipboardText(label.c_str());
				else if (e->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
					label = SDL_GetClipboardText();

				break;
			}

			case SDL_TEXTINPUT:
				if (!((e->text.text[0] == 'c' || e->text.text[0] == 'C') && (e->text.text[0] == 'v' || e->text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL))
					if ((int)label.size() * (font_size - 2) + 10 < sizes->w)
						label += e->text.text;

				break;

			case SDL_MOUSEBUTTONDOWN:
			{
				int x, y;
				SDL_GetMouseState(&x, &y);

				SDL_Point point = { x, y };

				if (!SDL_PointInRect(&point, sizes))
					focus = false;

				render();
				break;
			}
			}
			render();
		}
	}
	SDL_StopTextInput();
}

void Input::in_focus()
{
	focus = true;
	render();
}

void Input::out_focus()
{
	focus = false;
	render();
}

string Input::get_value()
{
	return label;
}

void Input::clear()
{
	label = "";
	render();
}

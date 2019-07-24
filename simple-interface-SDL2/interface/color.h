#pragma once
#include "SDL.h"

struct COLOR {
	// Темная тема
	/*COLOR() {
		background = { 0x33, 0x33, 0x33, 0x00 };
		element_blocked = { 0x2D, 0x2D, 0x30, 0x00 };
		element_border = { 0x43, 0x43, 0x46, 0x00 };
		element_background_click = { 0x2D, 0x2D, 0x2D, 0x00 };
		element_background_focus = { 0x1E, 0x1E, 0x1E, 0x00 };
		element_background_unfocus = { 0x1E, 0x1E, 0x1E, 0x00 };
		element_border_click = { 0x50, 0xA0, 0xDF, 0x00 };
		element_list_hover = { 0x00, 0x7A, 0xCC, 0x00 };
		element_background = { 0x1E, 0x1E, 0x1E, 0x00 };
		element_text = { 0xFF, 0xFF, 0xFF, 0xFF };
	}*/

	/*Тема фотошопа*/
	COLOR() {
		background = { 0x42, 0x42, 0x42, 0xFF };
		element_blocked = { 0x2D, 0x2D, 0x30, 0xFF };
		element_border = { 0x38, 0x38, 0x38, 0xFF };
		element_background_click = { 0x2D, 0x2D, 0x2D, 0xFF };
		element_background_focus = { 0x4f, 0x4f, 0x4f, 0xFF };
		element_background_unfocus = { 0x1E, 0x1E, 0x1E, 0xFF };
		element_border_click = { 0x50, 0xA0, 0xDF, 0xFF };
		element_list_hover = { 0x00, 0x7A, 0xCC, 0xFF };
		element_background = { 0x1E, 0x1E, 0x1E, 0xFF };
		element_text = { 0xFF, 0xFF, 0xFF, 0xFF };

		canvas_background = { 0xFF, 0xFF, 0xFF, 0xFF };
		canvas_black = { 0x00, 0x00, 0x00, 0xFF };
	}

	// Светлая тема
	/*COLOR() {
		background = { 0xF0, 0xF0, 0xF0, 0x00 };
		element_blocked = { 0xA0, 0xA0, 0xA0, 0x00 };
		element_border = { 0xAD, 0xAD, 0xAD, 0x00 };
		element_background_click = { 0xE5, 0xF1, 0xFB, 0x00 };
		element_background_focus = { 0xFD, 0xFD, 0xFD, 0x00 };
		element_background_unfocus = { 0xFD, 0xFD, 0xFD, 0x00 };
		element_border_click = { 0x50, 0xA0, 0xDF, 0x00 };
		element_list_hover = { 0x50, 0xA0, 0xDF, 0x00 };
		element_background = { 0xE1, 0xE1, 0xE1, 0x00 };
		element_text = { 0x00, 0x00, 0x00, 0x00 };
	}*/

	SDL_Color background;
	SDL_Color element_blocked;
	SDL_Color element_border;
	SDL_Color element_background_click;
	SDL_Color element_background_focus;
	SDL_Color element_background_unfocus;
	SDL_Color element_border_click;
	SDL_Color element_list_hover;
	SDL_Color element_background;
	SDL_Color element_text;

	SDL_Color canvas_background;
	SDL_Color canvas_black;
};
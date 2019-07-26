#include "itemList.h"

ItemList::~ItemList()
{
	delete item_sizes;
}

void ItemList::render()
{
	if (!display)
		return;

	SDL_Rect render_rect = *item_sizes;
	render_rect.x = sizes->x + sizes->w + 2;
	render_rect.y = sizes->y;


	// Отрисовка обводки
	SDL_Rect border = *sizes;
	border.x--;
	border.y--;
	border.w += 2;
	border.h += 2;
	SDL_SetRenderColor(renderer, Colors.element_border);
	SDL_RenderFillRect(renderer, &border);


	// Отрисовка тела
	if (block)
		SDL_SetRenderColor(renderer, Colors.element_blocked);
	else
		SDL_SetRenderColor(renderer, Colors.element_background);
	SDL_RenderFillRect(renderer, sizes);
	renderLabel(label, sizes);


	// Отрисовка изображения
	SDL_Rect dropButtonRect = { sizes->x + sizes->w - 15, sizes->y + 6, 8, 8 };
	SDL_RenderCopy(renderer, image_drop_button, NULL, &dropButtonRect);


	// Отрисовка выпадающего списка
	if (show_list && !block) {

		for (size_t i = 0; i < List.size(); i++)
		{
			if (List.at(i)->is_hover())
				SDL_SetRenderColor(renderer, Colors.element_list_hover);
			else
				SDL_SetRenderColor(renderer, Colors.element_background);

			SDL_RenderFillRect(renderer, &render_rect);

			renderLabel(List.at(i)->text, &render_rect, LEFT_ALIGN);
			render_rect.y += render_rect.h;
		}
	}
	else 
	{
		SDL_Rect clear_rect = { render_rect.x, render_rect.y, render_rect.w, (int)(render_rect.h * List.size()) };
		SDL_SetRenderColor(renderer, Colors.background);
		SDL_RenderFillRect(renderer, &clear_rect);
	}

	SDL_RenderPresent(renderer);
}

void ItemList::add(string text, int flag)
{
	Item* newItem = new Item;
	newItem->text = text;
	newItem->flag = flag;

	List.push_back(newItem);
	render();
}

void ItemList::open()
{
	show_list = true;
	render();
}

void ItemList::close()
{
	show_list = false;
	render();
}

bool ItemList::is_open()
{
	return show_list;
}

int ItemList::checkItemHover(int x, int y)
{
	if (block || !display || !show_list)
		return false;

	SDL_Point point = { x, y };

	SDL_Rect itemRect = *item_sizes;
	itemRect.x = sizes->x + sizes->w;
	itemRect.y = sizes->y;

	int flag = 0;
	for (size_t i = 0; i < List.size(); i++) {
		bool hov = SDL_PointInRect(&point, &itemRect);
		itemRect.y += itemRect.h;

		List.at(i)->Hover(false);

		if (hov) {
			flag = List.at(i)->flag;
			List.at(i)->Hover(true);
		}
	}
	return flag;
}

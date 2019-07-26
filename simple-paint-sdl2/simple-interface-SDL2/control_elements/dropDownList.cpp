#include "dropDownList.h"

DropDownList::~DropDownList()
{
	delete item_sizes;
}

void DropDownList::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w += 2;
		clearRect.h += 2;

		SDL_SetRenderColor(renderer, Colors::background);
		SDL_RenderFillRect(renderer, &clearRect);
		return;
	}

	SDL_Rect renderRect = *item_sizes;

	if (drop_type == LEFT_SIDE) {
		renderRect.x = sizes->x + sizes->w + 2;
		renderRect.y = sizes->y;
	}
	else if (drop_type == DOWN_SIDE) {
		renderRect.x = sizes->x;
		renderRect.y = sizes->y + sizes->h + 2;
	}

	// Отрисовка обводки
	SDL_Rect border = *sizes;
	border.x--;
	border.y--;
	border.w += 2;
	border.h += 2;
	SDL_SetRenderColor(renderer, Colors::element_border);
	SDL_RenderFillRect(renderer, &border);


	// Отрисовка тела
	if (block)
		SDL_SetRenderColor(renderer, Colors::element_blocked);
	else
		SDL_SetRenderColor(renderer, Colors::element_background_unfocus);

	SDL_RenderFillRect(renderer, sizes);
	renderLabel(label, sizes, LEFT_ALIGN);
	

	// Отрисовка изображения
	SDL_Rect dropButtonRect = { sizes->x + sizes->w - 15, sizes->y + 6, 8, 8 };
	SDL_RenderCopy(renderer, image_drop_button, NULL, &dropButtonRect);


	//SDL_RenderReadPixels(renderer, NULL, 0, surface->pixels, surface->pitch);
	////SDL_DestroyTexture(destTexture);
	////destTexture = SDL_CreateTextureFromSurface(renderer, surface);
	//SDL_UpdateTexture(destTexture, NULL, surface->pixels, surface->pitch);

	if (show_list && !block) 
	{
		for (size_t i = 0; i < List.size(); i++)
		{
			if (List.at(i)->is_block()) 
				SDL_SetRenderColor(renderer, Colors::element_blocked);
			else
				SDL_SetRenderColor(renderer, Colors::element_background);

			SDL_RenderFillRect(renderer, &renderRect);
			renderLabel(List.at(i)->text, &renderRect, LEFT_ALIGN);
			renderRect.y += renderRect.h;
		}
	}
	else 
	{
		//SDL_RenderClear(renderer);
		//SDL_RenderCopy(renderer, destTexture, NULL, NULL);
		//SDL_RenderPresent(renderer);

		//SDL_RenderReadPixels(renderer, NULL, 0, surface->pixels, surface->pitch);
		////SDL_DestroyTexture(destTexture);
		////destTexture = SDL_CreateTextureFromSurface(renderer, surface);
		//SDL_UpdateTexture(destTexture, NULL, surface->pixels, surface->pitch);

		SDL_Rect clearRect = { renderRect.x, renderRect.y, renderRect.w, (int)(renderRect.h * List.size()) };
		SDL_SetRenderDrawColor(renderer, Colors::background.r, Colors::background.g, Colors::background.b, Colors::background.a);
		SDL_RenderFillRect(renderer, &clearRect);

	
	}

	
	SDL_RenderPresent(renderer);
}

DropDownItem* DropDownList::add(string text, int flag)
{
	DropDownItem* newItem = new DropDownItem;
	newItem->text = text;
	newItem->flag = flag;

	List.push_back(newItem);
	render();
	return newItem;
}

void DropDownList::open(bool value)
{
	show_list = value;
	render();
}

bool DropDownList::open()
{
	return show_list;
}

int DropDownList::checkItemHover(int x, int y)
{
	if (block || !display || !show_list)
		return false;

	SDL_Point point = { x, y };

	SDL_Rect itemRect = *item_sizes;

	if (drop_type == LEFT_SIDE) {
		itemRect.x = sizes->x + sizes->w;
		itemRect.y = sizes->y;
	}
	else if (drop_type == DOWN_SIDE) {
		itemRect.x = sizes->x;
		itemRect.y = sizes->y + sizes->h;
	}

	int flag = 0;

	for (size_t i = 0; i < List.size(); i++) {
		bool hov = SDL_PointInRect(&point, &itemRect);
		itemRect.y += itemRect.h;

		if (hov) 
			if (!List.at(i)->is_block())
				flag = List.at(i)->flag;
	}
	flag_select = flag;
	return flag;
}

void DropDownList::setValue(string value)
{
	label = value;
	render();
}

string DropDownList::getValue()
{
	return label;
}

int DropDownList::getFlag()
{
	return flag_select;
}

const vector<DropDownItem*>* DropDownList::getItems()
{
	return &List;
}

void DropDownList::clear()
{
	label = "";
	render();
}

DropDownList* DropDownList::deleteItems()
{
	List.clear();
	render();
	return this;
}

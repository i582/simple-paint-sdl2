#include "interface.h"

void Interface::mouseMotion(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	
	for (size_t i = 0; i < ItemLists.size(); i++) 
		if (ItemLists.at(i)->checkItemHover(x, y))
			ItemLists.at(i)->render();

	
}

void Interface::mouseButtonDown(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);


	for (size_t i = 0; i < Buttons.size(); i++) {
		if (Buttons.at(i)->is_hover(x, y)) {

			Buttons.at(i)->Click(true);
			

			switch (i)
			{

				// ДОБАВЬТЕ СЮДА ВАШИ ИДЕНТИФИКАТОРЫ КНОПОК
			
			case -1: {
				break;
			}
			default: break;
			}
		}
	}
}

void Interface::mouseButtonUp(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (size_t i = 0; i < Buttons.size(); i++)
		Buttons.at(i)->Click(false);
	

	for (size_t i = 0; i < Inputs.size(); i++) {
		if (Inputs.at(i)->is_hover(x, y)) {
			Inputs.at(i)->in_focus();
			Inputs.at(i)->onEvent(event);
		}
	}


	for (size_t i = 0; i < ItemLists.size(); i++) {
		int flag = ItemLists.at(i)->checkItemHover(x, y);

		if (ItemLists.at(i)->is_hover(x, y)) {

			if (!ItemLists.at(i)->is_open()) {
				for (size_t i = 0; i < ItemLists.size(); i++) 
					ItemLists.at(i)->close();
				
				ItemLists.at(i)->open();
			}
			else 
				ItemLists.at(i)->close();
			
		}
		else {

			if (flag) {

				for (size_t i = 0; i < ItemLists.size(); i++)
					ItemLists.at(i)->close();
				

				switch (flag)
				{

					// ДОБАВЬТЕ СЮДА ВАШИ ИДЕНТИФИКАТОРЫ ЭЛЕМЕНТОВ СПИСКА КОТОРЫЕ ВЫ ХОТИТЕ ЗАДЕЙСТВОВАТЬ

				case -1: {
					break;
				}
				default: break;
				}
			}
			else {
				if (ItemLists.at(i)->is_open()) 
					ItemLists.at(i)->close();
			}
		}
	}


	for (size_t i = 0; i < DropDownLists.size(); i++)
	{
		int flag = DropDownLists.at(i)->checkItemHover(x, y);

		if (DropDownLists.at(i)->is_hover(x, y)) {

			if (!DropDownLists.at(i)->open()) {

				for (size_t j = 0; j < DropDownLists.size(); j++) {
					if (DropDownLists.at(j)->open()) {
						DropDownLists.at(j)->open(false);
						DropDownLists.at(j)->render();
					}
				}

				DropDownLists.at(i)->open(true);
			}
			else
				DropDownLists.at(i)->open(false);

			DropDownLists.at(i)->render();
		}
		else if (flag)
		{
			DropDownLists.at(i)->setValue(DropDownLists.at(i)->getItems()->at(flag - 1)->text);
			DropDownLists.at(i)->open(false);
			DropDownLists.at(i)->render();
		}
		else {
			if (DropDownLists.at(i)->open()) {
				DropDownLists.at(i)->open(false);
				DropDownLists.at(i)->render();
			}
		}
	}
}


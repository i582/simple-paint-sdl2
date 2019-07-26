#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "vector"

#include "Color.h"

#include "../control_elements/base_control.h"
#include "../control_elements/button.h"
#include "../control_elements/input.h"
#include "../control_elements/itemList.h"
#include "../control_elements/label.h"
#include "../control_elements/dropDownList.h"
#include "../control_elements/textField.h"

#include "../string_classes/String.h"
#include "../string_classes/ID_String.h"
#include "../string_classes/BIN_String.h"

#include "../window/window-class.h"
#include "../primitives/primitives.h"
#include "../viewport/viewport.h"

using namespace std;


class Interface {
private:
	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* tex;

	SDL_Event event;
	SDL_Texture* texture;

	short screenWidth;
	short screenHeight;

	COLOR Colors;

	// элементы интерфейса
	vector <Button*> Buttons;
	vector <Input*> Inputs;
	vector <ItemList*> ItemLists;
	vector <DropDownList*> DropDownLists;
	vector <Label*> Labels;
	vector <TextField*> TextFields;
	//



	// Элементы приложения
	bool ready_fill_classes;

	int count_ready;
	int count_element;
	vector <String*> ptrBaseClass;
	vector <int> type_ptrBaseClasses;

	int nowOperation;


	/**/
	vector <Window*> all_windows;

	SDL_Point mouse_coord;


	Viewport* viewport;
	Canvas* canvas;

public:
	Interface();
	Interface(short width, short height);
	~Interface();

private:
	void render();
	void onEvent();

	bool init();
	void setup();

	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);
	void mouseMotion(SDL_Event* event);

	void quit();

public:
	int onExecute();

};

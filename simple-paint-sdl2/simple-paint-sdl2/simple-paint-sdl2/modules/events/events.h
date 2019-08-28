#pragma once

typedef unsigned int Uint32;

enum Caller
{
	BUTTON = 0x00000000,
	MENU,
	CHECKBOX,
	RADIOBUTTON,
	TOOL,
};

enum Action
{
	BUTTON_PRESSED = 0x00000000,
	BUTTON_RELEASED,


	MENU_OPEN = 0x00000010,
	MENU_CLOSE,
	MENU_SELECT,

	CHECKBOX_CHECKED = 0x00000020,
	CHECKBOX_UNCHECKED,

	RADIOBUTTON_CHECKED = 0x00000030,

	TOOL_SELECTED = 0x000000040,

};


enum SystemID
{
	SYSTEM_EXIT = 0xFFFFFFF0,
	SYSTEM_COLLAPSE,
	SYSTEM_EXPAND
};

struct CommonEvent
{
	Uint32 caller;
	Uint32 action;
	Uint32 object_id;
};

struct MenuEvent
{
	Uint32 menu_id;
	Uint32 select_id;
};

class Event
{
public:
	CommonEvent common;
	MenuEvent menu;

public:
	/*
	 * simple
	 */
	Event(Caller caller, Action action, Uint32 object_id);

	/*
	 * menu
	 */
	Event(Caller caller, Action action, Uint32 menu_id, Uint32 select_id);



};
#include "events.h"

Event::Event(Caller caller, Action action, Uint32 object_id)
{
	this->common.caller = caller;
	this->common.action = action;
	this->common.object_id = object_id;

	this->menu.menu_id = object_id;
	this->menu.select_id = -1;
}

Event::Event(Caller caller, Action action, Uint32 menu_id, Uint32 select_id)
{
	this->common.caller = caller;
	this->common.action = action;
	this->common.object_id = menu_id;

	this->menu.menu_id = menu_id;
	this->menu.select_id = select_id;
}

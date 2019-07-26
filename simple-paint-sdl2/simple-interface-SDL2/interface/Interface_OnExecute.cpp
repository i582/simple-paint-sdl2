#include "interface.h"

int Interface::onExecute()
{
	init();
	setup();
	render();
	onEvent();

	return 0;
}

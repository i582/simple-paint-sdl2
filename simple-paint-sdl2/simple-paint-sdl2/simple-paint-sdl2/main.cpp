#include "modules/editor/editor.h"

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Rus");

	Editor* editor = Editor::get_instance();

	editor->run();

	delete editor;
	return 0;
}
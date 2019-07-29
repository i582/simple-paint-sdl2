#include "editor/editor.h"

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Rus");

	Editor editor(1200, 700);

	return editor.onExecute();
}
#include "interface/interface.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Rus");

	Interface newInterface(1200, 700);

	return newInterface.onExecute();
}
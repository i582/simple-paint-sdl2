#include "DropWindow.h"

DropWindow::DropWindow(string title, SDL_Rect* sizes, Uint32 flags) 
	: Window(title, sizes, flags)
{
	init();
}

void DropWindow::setup()
{
	SDL_SetRenderDrawColor(renderer, Colors::drop_down_back.r, Colors::drop_down_back.g, Colors::drop_down_back.b, 0xFF);

//	SDL_RenderPresent(renderer);

}

void DropWindow::render()
{
	SDL_SetRenderDrawColor(renderer, Colors::drop_down_back.r, Colors::drop_down_back.g, Colors::drop_down_back.b, 0xFF);

//	SDL_RenderPresent(renderer);
}

void DropWindow::mouseButtonDown(SDL_Event* e)
{
}

void DropWindow::mouseButtonUp(SDL_Event* e)
{
}

void DropWindow::mouseMotion(SDL_Event* e)
{
}

void DropWindow::mouseWheel(SDL_Event* e)
{
}

void DropWindow::keyDown(SDL_Event* e)
{
}

void DropWindow::keyUp(SDL_Event* e)
{
}

void DropWindow::textInput(SDL_Event* e)
{
}

void DropWindow::handleUserEvents(Event* ev)
{
}

void DropWindow::on_event(SDL_Event* e)
{
	
}

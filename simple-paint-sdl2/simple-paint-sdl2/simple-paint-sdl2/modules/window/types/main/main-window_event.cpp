#include "main-window.h"
#include "SDL_syswm.h"

void MainWindow::mouseButtonDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonDown(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseButtonDown(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseButtonDown(e);
	}
	
}

void MainWindow::mouseButtonUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseButtonUp(e);
	}

	if (toolbar->on_hover(mouse_coord.x, mouse_coord.y))
	{
		toolbar->mouseButtonUp(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseButtonUp(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseButtonUp(e);
	}
	
}

void MainWindow::mouseMotion(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y)) 
	{
		viewport->mouseMotion(e);
	}

	if (toolbar->on_hover(mouse_coord.x, mouse_coord.y))
	{
		toolbar->mouseMotion(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseMotion(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseMotion(e);
	}
}

void MainWindow::mouseWheel(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	if (viewport->on_hover(mouse_coord.x, mouse_coord.y))
	{
		viewport->mouseWheel(e);
	}

	if (layers_viewer->on_hover(mouse_coord.x, mouse_coord.y))
	{
		layers_viewer->mouseWheel(e);
	}

	if (container->on_hover(mouse_coord.x, mouse_coord.y))
	{
		container->mouseWheel(e);
	}
}

void MainWindow::keyDown(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);
}

void MainWindow::keyUp(SDL_Event* e)
{
	SDL_GetMouseState(&mouse_coord.x, &mouse_coord.y);

	// code
}

void MainWindow::systemEvent(SDL_Event* e)
{
	SDL_SysWMinfo info;
	SDL_VERSION(&info.version);

	SDL_GetWindowWMInfo(window, &info);

	
	switch (e->type)
	{
	
	case SDL_SYSWMEVENT:
		if (e->syswm.msg->msg.win.msg == WM_COMMAND)
		{
		
			switch (LOWORD(e->syswm.msg->msg.win.wParam))
			{

			case 122:
			{


				MessageBox(info.info.win.window, "safsaf", "Input", MB_ICONINFORMATION);



				return;
			}

			default:break;
			}
		}

		if (e->syswm.msg->msg.win.msg == WM_CREATE)
		{
			
			MessageBox(info.info.win.window, "safsaf", "Input", MB_ICONINFORMATION);
		}
		break;
	};
}

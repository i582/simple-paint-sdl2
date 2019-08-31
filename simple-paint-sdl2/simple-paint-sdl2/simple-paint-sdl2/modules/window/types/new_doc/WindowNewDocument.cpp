#include "WindowNewDocument.h"

NewDocumentWindow::NewDocumentWindow(string title, SDL_Rect* sizes, Uint32 flags)
	: Window(title, sizes, flags)
{
	init();
}

void NewDocumentWindow::setup()
{
	SDL_Rect* r = new SDL_Rect;
	*r = { 0, 0, width - 51, 35 };
	SDL_SetWindowHitTest(window, HitTest, r);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);



	background = IMG_LoadTexture(renderer, "././././resources/images/background.png");



	CreateControl(new ButtonImg(this, NULL, SYSTEM_EXIT, "", { width - 51, 1, 49, 34 }, Resources::texture_systemExit))
		->set_background_color({ 0x1f,0x1f, 0x1f, 0xff });
	
	CreateControl(new Label(this, NULL, LABEL_TEXT_CREATE, "Create new document", { 430, 20, 300, 30 }, Resources::font_lato_regular_25px))
		->set_background_color({ 0x1f,0x1f, 0x1f, 0xff });

	CreateControl(new Label(this, NULL, LABEL_TEXT_WIDTH, "Width", { 430, 70, 100, 20 }, Resources::font_lato_12px))
		->set_background_color({ 0x1f,0x1f, 0x1f, 0xff })
		->set_text_color({ 0xcd, 0xcd, 0xcd, 0xff });

	CreateControl(new Input(this, NULL, INPUT_WIDTH, "", { 430, 92, 70, 35 }, TTF_OpenFont("././././resources/fonts/Lato-Regular.ttf", 13)))
		->set_background_color({ 0x1f,0x1f, 0x1f, 0xff })
		->set_text_color({0xcd, 0xcd, 0xcd, 0xff});


	CreateControl(new Label(this, NULL, LABEL_TEXT_HEIGHT, "Height", { 430, 135, 100, 20 }, Resources::font_lato_12px))
		->set_background_color({ 0x1f,0x1f, 0x1f, 0xff })
		->set_text_color({ 0xcd, 0xcd, 0xcd, 0xff });

	CreateControl(new Input(this, NULL, INPUT_HEIGHT, "", { 430, 157, 70, 35 }, TTF_OpenFont("././././resources/fonts/Lato-Regular.ttf", 13)))
		->set_background_color({ 0x1f,0x1f, 0x1f, 0xff })
		->set_text_color({ 0xcd, 0xcd, 0xcd, 0xff });
	

	CreateControl(new Button(this, NULL, BUTTON_CREATE, "Create", { 430, 420, 80, 35 }, TTF_OpenFont("././././resources/fonts/Lato-Regular.ttf", 13)))
		->set_background_color({ 0x1f, 0x1f, 0x1f, 0xff });

	render();
}

void NewDocumentWindow::update()
{
	for (auto& control : controls)
	{
		control->update();
	}
}

void NewDocumentWindow::render()
{
	SDL_SetRenderTarget(renderer, NULL);

	SDL_RenderCopy(renderer, background, NULL, NULL);

	for (auto& control : controls)
	{
		control->update();
	}

	Primitives::renderer = renderer;
	Primitives::color = &Colors::element_border_click;
	Primitives::circle(400, 400, 100);

	SDL_SetRenderDrawColor(renderer, 0xc9, 0x50, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, NULL);

	SDL_RenderPresent(renderer);
}

Control* const NewDocumentWindow::CreateControl(Control* el)
{
	controls.push_back(el);
	return el;
}

SDL_HitTestResult NewDocumentWindow::HitTest(SDL_Window* window, const SDL_Point* area, void* data)
{
	if (SDL_PointInRect(area, ((SDL_Rect*)data)))
		return SDL_HITTEST_DRAGGABLE;

	return SDL_HITTEST_NORMAL;
}

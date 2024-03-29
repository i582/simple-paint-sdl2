#include "_Control.h"

Control::Control(SDL_Renderer* renderer, SDL_Texture* parent_target, SDL_Rect size, string text, int control_ID)
{
	this->renderer = renderer;
	this->parent_target = parent_target;
	this->texture = nullptr;
	this->text_texture = nullptr;
	this->text_rect = { 0, 0, 0, 0 };

	this->size = size;

	this->text = text;
	this->font = nullptr;

	this->background = Colors::element_background;
	this->color = Colors::element_text;

	this->control_ID = control_ID;
	this->group_ID = -1;

	this->blocked = false;
	this->display = true;
	this->click = false;
	this->focused = false;
	this->hovered = false;
	this->checked = false;

	this->is_updated = false;
	this->need_update = true;

	this->mouse_p = { 0, 0 };

	this->friends = nullptr;

	init();
}

Control::~Control()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(text_texture);
	TTF_CloseFont(font);
}

void Control::init()
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.w, size.h);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
}

void Control::render_text(string text, SDL_Rect place, int align, TTF_Font* font)
{
	if (text_texture == nullptr)
		render_text_(text, place, align, font);

//   SDL_RenderClear(renderer);
   SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, text_texture, nullptr, &text_rect);
//	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, parent_target);
}


void Control::render_text_(string text, SDL_Rect place, int align, TTF_Font* font)
{
	SDL_DestroyTexture(text_texture);

	if (text == "")
	{
		text_texture = nullptr;
		return;
	}

	SDL_Surface * text_surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);

	text_rect.w = text_surface->w;
	text_rect.h = text_surface->h;


	if (align == LEFT_ALIGN)
	{
		text_rect.x = 10;
	}
	else if (align == LEFT_NO_PAD_ALIGN)
	{
		text_rect.x = 0;
	}
	else if (align == CENTER_ALIGN)
	{
		text_rect.x = (int)((place.w - text_surface->w) / 2.);
	}

	text_rect.y = (int)(place.h / 2. - text_surface->h / 2.) + place.y;

	text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

	if (text_texture == nullptr)
		throw "Error memory allocated";

	SDL_FreeSurface(text_surface);
}

void Control::update()
{
//	if (is_updated == false || need_update == false)
//	{
		update_();
//		is_updated = true;
//	}

   SDL_SetRenderTarget(renderer, parent_target);

	SDL_RenderCopy(renderer, texture, nullptr, &size);

	SDL_SetRenderTarget(renderer, nullptr);
}

Control* const Control::clear()
{
	text = "";
	is_updated = false;
	text_texture = nullptr;
	return this;
}

string& Control::get_value()
{
	return text;
}

Control* Control::set_background_color(SDL_Color color)
{
	this->background = color;
	return this;
}

Control* Control::set_text_color(SDL_Color color)
{
	this->color = color;
	return this;
}

Control* const Control::block()
{
	blocked = true;
	focused = false;
	is_updated = false;
	return this;
}

Control* const Control::unlock()
{
	blocked = false;
	is_updated = false;
	return this;
}

bool Control::is_block()
{
	return blocked;
}

Control* const Control::show()
{
	display = true;
	is_updated = false;
	return this;
}

Control* const Control::hide()
{
	display = false;
	focused = false;
	is_updated = false;
	return this;
}

bool Control::is_show()
{
	return display;
}

Control* const Control::focus()
{
	focused = true;
	is_updated = false;
	return this;
}

Control* const Control::unfocus()
{
	focused = false;
	is_updated = false;
	return this;
}

bool Control::is_focus()
{
	return focused;
}

Control* const Control::check()
{
	checked = true;
	is_updated = false;
	return this;
}

Control* const Control::uncheck()
{
	checked = false;
	is_updated = false;
	return this;
}

bool Control::is_checked()
{
	return checked;
}

Control* const Control::hover()
{
	hovered = true;
	is_updated = false;
	return this;
}

Control* const Control::unhover()
{
	hovered = false;
	is_updated = false;
	return this;
}

bool Control::is_hover_()
{
	return hovered;
}

Control* const Control::do_update()
{
	is_updated = false;
	return this;
}

int Control::get_group_id()
{
	return group_ID;
}

auto Control::get_friends()
{
	return friends;
}

bool Control::have_friends()
{
	return friends != nullptr && friends->size();
}

bool Control::on_hover(int x, int y)
{
	SDL_Point point = { x, y };
	return SDL_PointInRect(&point, &size) && !blocked && display;
}

void Control::update_coord(int* x, int* y)
{
	*x -= size.x;
	*y -= size.y;
}

void Control::check_click_out()
{
	SDL_GetMouseState(&mouse_p.x, &mouse_p.y);
	if (!on_hover(mouse_p.x, mouse_p.y))
	{
		this->click = false;
		this->focused = false;
		this->hovered = false;
	}
}

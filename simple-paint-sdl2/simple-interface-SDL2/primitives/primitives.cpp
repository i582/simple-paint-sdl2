#include "primitives.h"
#include <ctime>

SDL_Renderer* Primitives::renderer = nullptr;
SDL_Color* Primitives::color = nullptr;
SDL_Texture* Primitives::tex = nullptr;

inline int Primitives::int_part(double num)
{
	return (int)num;
}

inline double Primitives::frac_part(double num)
{
	return num - (int)num;
}

void Primitives::render_pixel(int x, int y, double bright)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 0xFF * bright);
	SDL_RenderDrawPoint(renderer, x, y);
}

void Primitives::pixel(int x, int y)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 0xFF);
	SDL_RenderDrawPoint(renderer, x, y);
	SDL_RenderPresent(renderer);
}

void Primitives::rect(SDL_Rect* input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawRect(renderer, input_rect);
	SDL_RenderPresent(renderer);
}

void Primitives::rect(SDL_Rect input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawRect(renderer, &input_rect);
	SDL_RenderPresent(renderer);
}

void Primitives::fill_rect(SDL_Rect* input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(renderer, input_rect);
	SDL_RenderPresent(renderer);
}

void Primitives::fill_rect(SDL_Rect input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(renderer, &input_rect);
	SDL_RenderPresent(renderer);
}

void Primitives::line(int x1, int y1, int x2, int y2)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


	if (x1 == x2) {
		v_line(x1, y1, y2);
		return;
	}

	if (y1 == y2) {
		h_line(x1, y1, x2);
		return;
	}

	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	int dx = x2 - x1;
	int dy = y2 - y1;
	
	if (abs(dx) == abs(dy)) {
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
		SDL_RenderPresent(renderer);
		return;
	}

	double gradient = abs(dx) > abs(dy) ? (double)dy / (double)dx : (double)dx / (double)dy;
	double intery = abs(dx) > abs(dy) ? (y1) : (y1 > y2 ? x2 : x1) + gradient;
	
	if (y1 > y2)
		std::swap(y1, y2);

	if (abs(dx) >= abs(dy)) 
	{
		for (int x = x1; x < x2; x++) {
			render_pixel(x, int_part(intery), 1 - frac_part(intery));
			render_pixel(x, int_part(intery) + 1, frac_part(intery));
			intery += gradient;
		}
	}
	else 
	{
		for (int y = y1; y < y2; y++) {
			render_pixel(int_part(intery), y, 1 - frac_part(intery));
			render_pixel(int_part(intery) + 1, y, frac_part(intery));
			intery += gradient;
		}
	}

	
	SDL_RenderPresent(renderer);
}

void Primitives::line(SDL_Point* p1, SDL_Point* p2)
{
	line(p1->x, p1->y, p2->x, p2->y);
}

void Primitives::h_line(int x1, int y1, int x2)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y1);
	SDL_RenderPresent(renderer);
}

void Primitives::v_line(int x1, int y1, int y2)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawLine(renderer, x1, y1, x1, y2);
	SDL_RenderPresent(renderer);
}

void Primitives::line(int x1, int y1, int x2, int y2, int thickness)
{
	if (thickness == 1)
		line(x1, y1, x2, y2);

	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	
	

	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	int sign_y = 1;
	if (y1 > y2)
		sign_y = -1;
	

	SDL_Point p1, p2, p3, p4;
	double half_thickness = thickness / 2.;

	int dx = x2 - x1;
	int dy = y2 - y1;

	double sqr2 = 1.4142;

	double gradient_x = abs((double)dy / (double)dx);
	double gradient_y = abs((double)dx / (double)dy);

	

	int x_shift = round(sqr2 * half_thickness / (gradient_y + 1));
	int y_shift = round(sqr2 * half_thickness / (gradient_x + 1));

	p1.x = x1 - x_shift;
	p1.y = y1 + y_shift * sign_y;

	p2.x = x1 + x_shift;
	p2.y = y1 - y_shift * sign_y;

	p3.x = x2 - x_shift;
	p3.y = y2 + y_shift * sign_y;

	p4.x = x2 + x_shift;
	p4.y = y2 - y_shift * sign_y;

	line(&p1, &p2);
	line(&p3, &p4);

	line(&p1, &p3);
	line(&p2, &p4);

	SDL_RenderPresent(renderer);
}

void Primitives::line(SDL_Point* p1, SDL_Point* p2, int thickness)
{
	line(p1->x, p1->y, p2->x, p2->y, thickness);
}

void Primitives::h_line(int x1, int y1, int x2, int thickness)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	int half_thickness = (int)(thickness / 2);

	if (thickness % 2 == 0) {
		for (int i = -half_thickness; i < half_thickness; i++)
			SDL_RenderDrawLine(renderer, x1, y1 + i, x2, y1 + i);
	}
	else {
		SDL_RenderDrawLine(renderer, x1, y1, x2, y1);
		int half_thickness = (int)(thickness / 2);

		for (int i = 0; i < half_thickness; i++)
			SDL_RenderDrawLine(renderer, x1, y1 + 1 + i, x2, y1 + 1 + i);

		for (int i = 0; i < half_thickness; i++)
			SDL_RenderDrawLine(renderer, x1, y1 - 1 - i, x2, y1 - 1 - i);
	}

	SDL_RenderPresent(renderer);
}

void Primitives::v_line(int x1, int y1, int y2, int thickness)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	int half_thickness = (int)(thickness / 2);

	if (thickness % 2 == 0) {
		for (int i = -half_thickness; i < half_thickness; i++)
			SDL_RenderDrawLine(renderer, x1 + i, y1, x1 + i, y2);
	}
	else {
		SDL_RenderDrawLine(renderer, x1, y1, x1, y2);
		int half_thickness = (int)(thickness / 2);

		for (int i = 0; i < half_thickness; i++)
			SDL_RenderDrawLine(renderer, x1 + 1 + i, y1, x1 + 1 + i, y2);

		for (int i = 0; i < half_thickness; i++)
			SDL_RenderDrawLine(renderer, x1 - 1 - i, y1, x1 - 1 - i, y2);
	}

	SDL_RenderPresent(renderer);
}

void Primitives::circle(int x, int y, int rad)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);


	int x1 = 0;
	int y1 = rad;

	int delta = 1 - 2 * rad;
	int error = 0;

	while (y1 != -1) 
	{
		//SDL_RenderDrawPoint(renderer, x + x1, y + y1); // низ право
		//SDL_RenderDrawPoint(renderer, x + x1, y - y1); // верх право
		//SDL_RenderDrawPoint(renderer, x - x1, y + y1); // низ лево
		SDL_RenderDrawPoint(renderer, x - x1, y - y1); // вверх лево

		
		

		error = 2 * (delta + y1) - 1;

		if ((delta < 0) && (error <= 0)) {
			x1++;
			delta += 2 * x1 + 1;
			continue;
		}
		if ((delta > 0) && (error > 0)) {
			y1--;
			delta -= 2 * y1 + 1;
			continue;
		}
		x1++;
		delta += 2 * (x1 - y1);
		y1--;
	}

	SDL_RenderPresent(renderer);
}

void Primitives::circle(SDL_Point* center, int rad)
{
	circle(center->x, center->y, rad);
}

void Primitives::fill_circle(int x, int y, int rad)
{
	circle(x, y, rad);
	fill(x, y);
}

void Primitives::fill_circle(SDL_Point* center, int rad)
{
	fill_circle(center->x, center->y, rad);
}

void Primitives::line_shape(SDL_Point* points, int count)
{
}

void Primitives::rounded_rect(SDL_Rect* input_rect)
{
}

void Primitives::rounded_fill_rect(SDL_Rect* input_rect)
{
}

void Primitives::fill(int x, int y)
{
	unsigned int start_time = clock();

	SDL_RenderPresent(renderer);

	int width, height;

	
	SDL_QueryTexture(tex, NULL, NULL, &width, &height);
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	SDL_RenderReadPixels(renderer, NULL, surface->format->format, surface->pixels, surface->pitch);
	
	if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface);

	std::queue <Uint32*> queue_pixel;

	int count_shift = 4;
	int shifts[4] = 
	{ 
		-surface->w,
		1,
		surface->w,
		-1
	};

	
	Uint32 cur_color = SDL_MapRGBA(surface->format, color->r, color->g, color->b, color->a);
	Uint32 color_fill_pixel;
	Uint32 color_pixel;

	int byte_shift = surface->pitch / surface->w;

	Uint32* psrc = (Uint32*)((int)surface->pixels + (y * surface->pitch + byte_shift * (x - 1)));
	
	color_fill_pixel = *psrc;
	*psrc = cur_color;
	
	queue_pixel.push(psrc);


	

	Uint32* first_pixel = (Uint32*)surface->pixels;
	Uint32* last_pixel = (Uint32*)((int)surface->pixels + ((height - 1) * surface->pitch + byte_shift * (width - 1)));

	Uint32* now_pixel;
	Uint32* temp_pixel;
	while (!queue_pixel.empty()) 
	{
		now_pixel = queue_pixel.front();
		queue_pixel.pop();
		
		for (int i = 0; i < count_shift; i++)
		{
			temp_pixel = now_pixel + shifts[i];

			if (temp_pixel > first_pixel && temp_pixel < last_pixel)
			{
				color_pixel = *temp_pixel;

				if (color_pixel == color_fill_pixel) 
				{
					queue_pixel.push(temp_pixel);
					*temp_pixel = cur_color;
					
				}
			}
		}
	}

	if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);




	SDL_Texture* ready = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect ren_rec = { 0, 0, width, height };
	SDL_RenderCopy(renderer, ready, NULL, &ren_rec);
	SDL_RenderPresent(renderer);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(ready);

	time_t end_time = clock();

	std::cout << "runtime = " << (end_time - start_time) / 1000.0 << std::endl;
	return;
}

void Primitives::fill(SDL_Point* p)
{
	fill(p->x, p->y);
}

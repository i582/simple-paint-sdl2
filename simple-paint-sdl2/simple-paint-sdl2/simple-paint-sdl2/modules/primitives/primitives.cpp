#include "primitives.h"
#include <ctime>

// require
SDL_Renderer* Primitives::renderer = nullptr;
SDL_Color* Primitives::color = nullptr;

// for fill
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
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, (Uint8)(0xFF * bright));
	SDL_RenderDrawPoint(renderer, x, y);
}

void Primitives::circle_part(int x, int y, int rad, int part)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);


	int x1 = 0;
	int y1 = rad;

	int delta = 1 - 2 * rad;
	int error = 0;

	while (y1 != 0 || x1 < rad + 1)
	{
		if (part == 3)
			SDL_RenderDrawPoint(renderer, x + x1, y + y1); // ��� �����

		if (part == 2)
			SDL_RenderDrawPoint(renderer, x + x1, y - y1); // ���� �����

		if (part == 4)
			SDL_RenderDrawPoint(renderer, x - x1, y + y1); // ��� ����

		if (part == 1)
			SDL_RenderDrawPoint(renderer, x - x1, y - y1); // ����� ����




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

//	// SDL_RenderPresent(renderer);
}

void Primitives::pixel(int x, int y)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 0xFF);
	SDL_RenderDrawPoint(renderer, x, y);
	// SDL_RenderPresent(renderer);
}

void Primitives::rect(SDL_Rect* input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawRect(renderer, input_rect);
	// SDL_RenderPresent(renderer);
}

void Primitives::rect(SDL_Rect* input_rect, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(renderer, input_rect);
	// SDL_RenderPresent(renderer);
}

void Primitives::rect(SDL_Rect input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawRect(renderer, &input_rect);
	// SDL_RenderPresent(renderer);
}

void Primitives::fill_rect(SDL_Rect* input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(renderer, input_rect);
	// SDL_RenderPresent(renderer);
}

void Primitives::fill_rect(SDL_Rect input_rect)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(renderer, &input_rect);
	// SDL_RenderPresent(renderer);
}

void Primitives::fill_rect(SDL_Rect* input_rect, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, input_rect);
	// SDL_RenderPresent(renderer);
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
		// SDL_RenderPresent(renderer);
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

	
	// SDL_RenderPresent(renderer);
}

void Primitives::line(SDL_Point* p1, SDL_Point* p2)
{
	line(p1->x, p1->y, p2->x, p2->y);
}

void Primitives::h_line(int x1, int y1, int x2)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y1);
	// SDL_RenderPresent(renderer);
}

void Primitives::v_line(int x1, int y1, int y2)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderDrawLine(renderer, x1, y1, x1, y2);
	// SDL_RenderPresent(renderer);
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

	

	int x_shift = (int)(round(sqr2 * half_thickness / (gradient_y + 1)));
	int y_shift = (int)(round(sqr2 * half_thickness / (gradient_x + 1)));

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

	// SDL_RenderPresent(renderer);
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

	// SDL_RenderPresent(renderer);
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

	// SDL_RenderPresent(renderer);
}

void Primitives::circle(int x, int y, int rad)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);


	//int x1 = 0;
	//int y1 = rad;

	//int delta = 1 - 2 * rad;
	//int error = 0;

	//while (y1 != -1) 
	//{
	//	SDL_RenderDrawPoint(renderer, x + x1, y + y1); // ��� �����
	//	SDL_RenderDrawPoint(renderer, x + x1, y - y1); // ���� �����
	//	SDL_RenderDrawPoint(renderer, x - x1, y + y1); // ��� ����
	//	SDL_RenderDrawPoint(renderer, x - x1, y - y1); // ����� ����

	//	
	//	

	//	error = 2 * (delta + y1) - 1;

	//	if ((delta < 0) && (error <= 0)) {
	//		x1++;
	//		delta += 2 * x1 + 1;
	//		continue;
	//	}
	//	if ((delta > 0) && (error > 0)) {
	//		y1--;
	//		delta -= 2 * y1 + 1;
	//		continue;
	//	}
	//	x1++;
	//	delta += 2 * (x1 - y1);
	//	y1--;
	//}

	
	// SDL_RenderPresent(renderer);
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

void Primitives::rounded_rect(SDL_Rect input_rect, int rad)
{
	rounded_rect(&input_rect, rad);
}

void Primitives::rounded_rect(SDL_Rect* input_rect, int rad)
{
	int x1 = input_rect->x,
		y1 = input_rect->y + 1,
		x2 = input_rect->x + input_rect->w - 1,
		y2 = input_rect->y + input_rect->h - 1;

	int xx1, xx2;
	int yy1, yy2;

	xx1 = x1 + rad;
	xx2 = x2 - rad;
	yy1 = y1 + rad;
	yy2 = y2 - rad;

	circle_part(xx1, yy1, rad, 1);
	circle_part(xx2, yy1, rad, 2);
	circle_part(xx1, yy2, rad, 4);
	circle_part(xx2, yy2, rad, 3);

	h_line(xx1, y1, xx2);
	h_line(xx1, y2, xx2);

	v_line(x1, yy1, yy2);
	v_line(x2, yy1, yy2);



	/*int x1 = input_rect->x, 
		y1 = input_rect->y, 
		x2 = input_rect->x + input_rect->w, 
		y2 = input_rect->y + input_rect->h;


	if (x1 > x2)
		std::swap(x1, x2);
	
	if (y1 > y2)
		std::swap(y1, y2);

	Sint16 xx1, xx2;
	Sint16 yy1, yy2;

	xx1 = x1 + rad;
	xx2 = x2 - rad;
	yy1 = y1 + rad;
	yy2 = y2 - rad;
	arc(xx1, yy1, rad, 180, 270);
	arc(xx2, yy1, rad, 270, 360);
	arc(xx1, yy2, rad, 90, 180);
	arc(xx2, yy2, rad, 0, 90);

	if (xx1 <= xx2)
	{
		h_line(xx1, xx2, y1);
		h_line(xx1, xx2, y2);
	}

	if (yy1 <= yy2)
	{
		v_line(x1, yy1, yy2);
		v_line(x2, yy1, yy2);
	}
*/
}

void Primitives::rounded_fill_rect(SDL_Rect input_rect, int rad)
{
	rounded_fill_rect(&input_rect, rad);
}

void Primitives::rounded_fill_rect(SDL_Rect* input_rect, int rad)
{
	rounded_rect(input_rect, rad);
	fill(input_rect->x + rad, input_rect->y + rad);
}

void Primitives::fill(int x, int y)
{
	unsigned int start_time = clock();

	// SDL_RenderPresent(renderer);

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

	Uint32* psrc = (Uint32*)((int64_t)surface->pixels + (y * surface->pitch + byte_shift * (x - 1)));
	
	color_fill_pixel = *psrc;
	*psrc = cur_color;
	
	queue_pixel.push(psrc);

	
	

	Uint32* first_pixel = (Uint32*)surface->pixels;
	Uint32* last_pixel = (Uint32*)((int64_t)surface->pixels + ((height - 1) * surface->pitch + byte_shift * (width - 1)));

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
	// SDL_RenderPresent(renderer);

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

void Primitives::arc(int x, int y, int rad, int start, int end)
{
	int r = color->r, 
		g = color->g, 
		b = color->b, 
		a = color->a;
	

	Sint16 cx = 0;
	Sint16 cy = rad;
	Sint16 df = 1 - rad;
	Sint16 d_e = 3;
	Sint16 d_se = -2 * rad + 5;
	Sint16 xpcx, xmcx, xpcy, xmcy;
	Sint16 ypcy, ymcy, ypcx, ymcx;
	Uint8 drawoct;
	int startoct, endoct, oct, stopval_start = 0, stopval_end = 0;
	double dstart, dend, temp = 0.;

	

	
	drawoct = 0;

	start %= 360;
	end %= 360;
	while (start < 0) start += 360;
	while (end < 0) end += 360;
	start %= 360;
	end %= 360;

	startoct = start / 45;
	endoct = end / 45;
	oct = startoct - 1;

	do 
	{
		oct = (oct + 1) % 8;

		if (oct == startoct) 
		{
			dstart = (double)start;
			switch (oct)
			{
			case 0:
			case 3:
				temp = sin(dstart * M_PI / 180.);
				break;
			case 1:
			case 6:
				temp = cos(dstart * M_PI / 180.);
				break;
			case 2:
			case 5:
				temp = -cos(dstart * M_PI / 180.);
				break;
			case 4:
			case 7:
				temp = -sin(dstart * M_PI / 180.);
				break;
			}
			temp *= rad;
			stopval_start = (int)temp;


			if (oct % 2) drawoct |= (1 << oct);		
			else		 drawoct &= 255 - (1 << oct);
		}
		if (oct == endoct)
		{
			dend = (double)end;
			switch (oct)
			{
			case 0:
			case 3:
				temp = sin(dend * M_PI / 180);
				break;
			case 1:
			case 6:
				temp = cos(dend * M_PI / 180);
				break;
			case 2:
			case 5:
				temp = -cos(dend * M_PI / 180);
				break;
			case 4:
			case 7:
				temp = -sin(dend * M_PI / 180);
				break;
			}
			temp *= rad;
			stopval_end = (int)temp;

			if (startoct == endoct)
			{
				if (start > end)
				{
					drawoct = 255;
				}
				else
				{
					drawoct &= 255 - (1 << oct);
				}
			}
			else if (oct % 2) drawoct &= 255 - (1 << oct);
			else			  drawoct |= (1 << oct);
		}
		else if (oct != startoct)
		{ 
			drawoct |= (1 << oct);
		}
	} while (oct != endoct);



	SDL_SetRenderDrawBlendMode(renderer, (a == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);


	do
	{
		ypcy = y + cy;
		ymcy = y - cy;
		if (cx > 0)
		{
			xpcx = x + cx;
			xmcx = x - cx;

			if (drawoct & 4)  pixel(xmcx, ypcy);
			if (drawoct & 2)  pixel(xpcx, ypcy);
			if (drawoct & 32) pixel(xmcx, ymcy);
			if (drawoct & 64) pixel(xpcx, ymcy);
		}
		else
		{
			if (drawoct & 96) pixel(x, ymcy);
			if (drawoct & 6)  pixel(x, ypcy);
		}

		xpcy = x + cy;
		xmcy = x - cy;
		if (cx > 0 && cx != cy)
		{
			ypcx = y + cx;
			ymcx = y - cx;
			if (drawoct & 8)   pixel(xmcy, ypcx);
			if (drawoct & 1)   pixel(xpcy, ypcx);
			if (drawoct & 16)  pixel(xmcy, ymcx);
			if (drawoct & 128) pixel(xpcy, ymcx);
		}
		else if (cx == 0)
		{
			if (drawoct & 24)  pixel(xmcy, y);
			if (drawoct & 129) pixel(xpcy, y);
		}


		if (stopval_start == cx)
		{
			if (drawoct & (1 << startoct)) drawoct &= 255 - (1 << startoct);
			else						   drawoct |= (1 << startoct);
		}
		if (stopval_end == cx)
		{
			if (drawoct & (1 << endoct)) drawoct &= 255 - (1 << endoct);
			else						 drawoct |= (1 << endoct);
		}


		if (df < 0)
		{
			df += d_e;
			d_e += 2;
			d_se += 2;
		}
		else
		{
			df += d_se;
			d_e += 2;
			d_se += 4;
			cy--;
		}
		cx++;
	} while (cx <= cy);

}


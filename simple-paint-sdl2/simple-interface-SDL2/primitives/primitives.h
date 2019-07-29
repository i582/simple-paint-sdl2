#pragma once
#include "SDL.h"
#include "iostream"
#include "vector"
#include "../color_scheme/color.h"
#include "queue"

class Primitives{
public:
	static SDL_Renderer* renderer;
	static SDL_Color* color;
	static SDL_Texture* tex;

private:
	static inline int int_part(double num);
	static inline double frac_part(double num);

	static void render_pixel(int x, int y, double bright);

public:
	/*
	 * Отрисовка пикселя
	 */
	static void pixel(int x, int y);

	/*
	 * Отрисовка контурного прямоугольника
	 */
	static void rect(SDL_Rect* input_rect);
	static void rect(SDL_Rect input_rect);

	/*
	 * Отрисовка закрашенного прямоугольника
	 */
	static void fill_rect(SDL_Rect* input_rect);
	static void fill_rect(SDL_Rect input_rect);

	/*
	 * Отрисовка линии шириной в 1 пиксель
	 */
	static void line(int x1, int y1, int x2, int y2);
	static void line(SDL_Point* p1, SDL_Point* p2);

	/*
	 * Отрисовка горизонтальной линии шириной в 1 пиксель
	 */
	static void h_line(int x1, int y1, int x2);

	/*
	 * Отрисовка вертикальной линии шириной в 1 пиксель
	 */
	static void v_line(int x1, int y1, int y2);



	/*
	 * Отрисовка линии шириной в thickness пикселей
	 */
	static void line(int x1, int y1, int x2, int y2, int thickness);
	static void line(SDL_Point* p1, SDL_Point* p2, int thickness);

	/*
	 * Отрисовка горизонтальной линии шириной в thickness пикселей
	 */
	static void h_line(int x1, int y1, int x2, int thickness);

	/*
	 * Отрисовка вертикальной линии шириной в thickness пикселей
	 */
	static void v_line(int x1, int y1, int y2, int thickness);


	/*
	 * Отрисовка контурного круга
	 */
	static void circle(int x, int y, int rad);
	static void circle(SDL_Point* center, int rad);

	static void circle_smooth(int x, int y, int rad);
	/*
	 * Отрисовка закрашенного круга
	 */
	static void fill_circle(int x, int y, int rad);
	static void fill_circle(SDL_Point* center, int rad);

	/*
	 * Отрисовка несколько линий друг за другом
	 */
	static void line_shape(SDL_Point* points, int count);

	
	/*
	 * Отрисовка контурного прямоугольника с скругленными краями
	 */
	static void rounded_rect(SDL_Rect* input_rect);

	/*
	 * Отрисовка закрашенного прямоугольника с скругленными краями
	 */
	static void rounded_fill_rect(SDL_Rect* input_rect);


	/*
	 * Заливка области с цветом как и у пикселя в точке p {x, y}
	 */
	static void fill(int x, int y);
	static void fill(SDL_Point* p);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:23:48 by gdel-val          #+#    #+#             */
/*   Updated: 2024/07/03 21:23:54 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		temp;
	int			color;

	z.a = 0;
	z.b = 0;
	c.a = scale_nums(x, -2, 2, WIDTH) * fractal->zoomx + fractal->shiftx;
	c.b = scale_nums(y, 2, -2, HEIGHT) * fractal->zoomy + fractal->shifty;
	i = -1;
	while (++i < fractal->iter)
	{
		z = complex_square(z);
		z.a = z.a + c.a;
		z.b = z.b + c.b;
		if ((z.a * z.a + z.b * z.b) > 2)
		{
			color = scale_nums(i, fractal->color, fractal->color * 10,
					fractal->iter);
			color_pixel(x, y, &fractal->img, color);
			return ;
		}
		color_pixel(x, y, &fractal->img, BLACK);
	}
}

void	fractol_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.a = (scale_nums(x, -2, 2, WIDTH) * fractal->zoomx) + fractal->shiftx;
	z.b = (scale_nums(y, 2, -2, HEIGHT) * fractal->zoomx) + fractal->shifty;
	c.a = fractal->julia_a;
	c.b = fractal->julia_b;
	while (++i < fractal->iter)
	{
		z = complex_sum(complex_square(z), c);
		if ((z.a * z.a) + (z.b * z.b) > 2)
		{
			color = scale_nums(i, fractal->color, fractal->color * 6,
					fractal->iter);
			color_pixel(x, y, &fractal->img, color);
			return ;
		}
	}
	color_pixel(x, y, &fractal->img, BLACK);
}

void	fractol_four(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		temp;
	int			color;

	z.a = 0;
	z.b = 0;
	c.a = scale_nums(x, -2, 2, WIDTH) * fractal->zoomx + fractal->shiftx;
	c.b = scale_nums(y, 2, -2, HEIGHT) * fractal->zoomy + fractal->shifty;
	i = -1;
	while (++i < fractal->iter)
	{
		z = complex_square(complex_square(complex_square(z)));
		z.a = z.a + c.a;
		z.b = z.b + c.b;
		if ((z.a * z.a + z.b * z.b) > 2)
		{
			color = scale_nums(i, fractal->color, fractal->color * 10,
					fractal->iter);
			color_pixel(x, y, &fractal->img, color);
			return ;
		}
		color_pixel(x, y, &fractal->img, BLACK);
	}
}

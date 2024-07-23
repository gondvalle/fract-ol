/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:20:42 by gdel-val          #+#    #+#             */
/*   Updated: 2024/04/09 19:20:45 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	plot_start(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (!fractal->mlx_connect)
		mlx_error(fractal);
	fractal->mlx_open = mlx_new_window(fractal->mlx_connect, WIDTH,
			HEIGHT, fractal->name);
	if (!fractal->mlx_open)
		mlx_error(fractal);
	fractal->img.img = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (!fractal->img.img)
		mlx_error(fractal);
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img,
			&fractal->img.color, &fractal->img.line_length,
			&fractal->img.end_line);
	if (!fractal->img.pixel)
		mlx_error(fractal);
	data_init(fractal);
	mlx_hook(fractal->mlx_open, 17, 0, close_window, fractal);
}

void	color_pixel(int x, int y, t_img *img, int color)
{
	int	displacement;

	displacement = (y * img->line_length) + ((img->color / 8) * x);
	*(unsigned int *)(img->pixel + displacement) = color;
}

void	plot_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
				fractol_mandelbrot(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "julia", 5))
				fractol_julia(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "four", 5))
				fractol_four(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_open,
		fractal->img.img, 0, 0);
}

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

// void	key_hook()

// void	data_start(t_fractal *fractal)
// {

// }

void	plot_start(t_fractal *fractal)
{
	fractal->mlx_conect = mlx_init();
	if (!fractal->mlx_conect)
		mlx_error(fractal);
	fractal->mlx_open = mlx_new_window(fractal->mlx_conect, WIDTH,
			HEIGHT, fractal->name);
	if (!fractal->mlx_open)
		mlx_error(fractal);
	fractal->img.img = mlx_new_image(fractal->mlx_conect, WIDTH, HEIGHT);
	if (!fractal->img.img)
		mlx_error(fractal);
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img, &fractal->img.color,
			&fractal->img.line_length, &fractal->img.end_line);
	if (!fractal->img.pixel)
		mlx_error(fractal);
	//data_start(fractal);
}
void	color_pixel(int x, int y, t_img *img, int color)
{
	int	displacement;

	displacement = (y * img->line_length) + ((img->color / 8) * x);
	*(unsigned int *)(img->pixel + displacement) = color;
}

void	fractol_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
    t_complex	c;
    int			i;
    double		temp;
	int			color;

    z.a = 0;
    z.b = 0;
    c.a = scale_nums(x, -2, 2, 0, WIDTH);
    c.b = scale_nums(y, 2, -2, 0, HEIGHT);
    i = -1;
    while(++i < 60)
    {
        temp = z.a * z.a - z.b * z.b;
        z.b = 2 * z.a * z.b;
        z.a = temp + c.a;
        z.b = z.b + c.b;
		//if (isinf(z.a * z.a + z.b * z.b))
		if ((z.a * z.a + z.b * z.b) > 2)
		{
			color = scale_nums(i, BLACK, WHITE, 0, 60);
			color_pixel(x, y, &fractal->img, color);
			return ;
		}
		color_pixel(x, y, &fractal->img, TURQUOISE);
    }
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
			fractol_mandelbrot(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_conect, fractal->mlx_open, fractal->img.img, 0, 0);
}

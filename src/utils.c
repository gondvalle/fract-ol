/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:07:05 by gdel-val          #+#    #+#             */
/*   Updated: 2024/07/01 20:07:09 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mlx_error(t_fractal *fractal)
{
	if (fractal->mlx_open)
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_open);
	if (fractal->mlx_connect)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

double	scale_nums(double i, double sca_min, double sca_max, double max)
{
	double	sca;
	double	new_sca;
	double	resca;
	double	num;

	sca = max - 0;
	new_sca = sca_max - sca_min;
	resca = new_sca / sca;
	num = sca_min + (i * resca);
	return (num);
}

int	key_hook(int keysym, t_fractal *fractal)
{
	printf("%i\n", keysym);
	if (keysym == 65307)
	{
		close_window(fractal);
		exit(0);
	}
	else if (keysym == 65361)
		fractal->shiftx += (0.5 * fractal->zoomx);
	else if (keysym == 65363)
		fractal->shiftx -= (0.5 * fractal->zoomx);
	else if (keysym == 65362)
		fractal->shifty -= (0.5 * fractal->zoomx);
	else if (keysym == 65364)
		fractal->shifty += (0.5 * fractal->zoomx);
	else if (keysym == 106)
		fractal->iter += 10;
	else if (keysym == 107)
		fractal->iter -= 10;
	else if (keysym == 99)
		fractal->color += 1000;
	plot_render(fractal);
	return (0);
}

int	mouse_hook(int keysym, int x, int y, t_fractal *fractal)
{
	printf("%i\n", keysym);
	if (keysym == 4)
		zoom_out(fractal, x, y);
	else if (keysym == 5)
		zoom_in(fractal, x, y);
	plot_render(fractal);
	return (0);
}

void	buttons(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_open, key_hook, fractal);
	mlx_mouse_hook(fractal->mlx_open, mouse_hook, fractal);
	mlx_loop(fractal->mlx_connect);
}

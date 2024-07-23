/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:51:55 by gdel-val          #+#    #+#             */
/*   Updated: 2024/04/03 16:54:20 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->iter = 100;
	fractal->shiftx = 0.0;
	fractal->shifty = 0.0;
	fractal->zoomx = 1.0;
	fractal->zoomy = 1.0;
	fractal->zoom_ship = 1.0;
	fractal->error = 0;
	fractal->color = AQUAMARINE;
}

void	julia_error(int error)
{
	ft_putstr_fd("Incorrect Julia parameters try -0.8 0.156\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argn, char **argv)
{
	t_fractal	fractal;

	if (argn == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal.name = argv[1];
		fractal.julia_a = ft_atodbl(argv[2], &fractal);
		fractal.julia_b = ft_atodbl(argv[3], &fractal);
		if (fractal.error == 1)
			julia_error(fractal.error);
	}
	else if (argn == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0
			|| (ft_strncmp(argv[1], "four", 10) == 0)))
		fractal.name = argv[1];
	else
	{
		ft_putstr_fd("Please enter mandelbrot or ", 2);
		return (ft_putstr_fd("try julia -0.8 0.156 or four", 2), 0);
	}
	plot_start(&fractal);
	plot_render(&fractal);
	buttons(&fractal);
}

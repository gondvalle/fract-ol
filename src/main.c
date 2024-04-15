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

int	main(int argn, char **argv)
{
	t_fractal	fractal;

	if (argn == 4 && ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
	}
	else if (argn == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
		fractal.name = argv[1];
	else
		return (ft_putstr_fd("Error\n", 2), 0);
	plot_start(&fractal);
	
}

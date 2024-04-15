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
		return (mlx_error(fractal), exit(EXIT_FAILURE));
	fractal->mlx_open = mlx_new_window(fractal->mlx_conect, WIDTH,
			HEIGHT, fractal->name);
	if (!fractal->mlx_conect)
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	fractal->img.img = mlx_new_image(fractal->mlx_conect, WIDTH, HEIGHT);
	if (!fractal->img.img)
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	fractal->img.img = mlx_get_data_addr(fractal->img.img, &fractal->img.color,
			&fractal->img.line_length, &fractal->img.end_line);
	if (!fractal->img.img)
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	data_start(fractal);
}

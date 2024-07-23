/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:48:58 by gdel-val          #+#    #+#             */
/*   Updated: 2024/07/01 22:49:00 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_fractal *fractal, int x, int y)
{
	int	aux_x;
	int	aux_y;

	aux_x = x;
	aux_y = y;
	fractal->zoomx *= 0.9;
	fractal->zoomy *= 0.9;
	fractal->shiftx += scale_nums(aux_x, -fractal->zoomx,
			fractal->zoomy, WIDTH) * 0.19;
	fractal->shifty += scale_nums(aux_y, fractal->zoomx,
			-fractal->zoomy, WIDTH) * 0.19;
}

void	zoom_out(t_fractal *fractal, int x, int y)
{
	int	aux_x;
	int	aux_y;

	aux_x = x;
	aux_y = y;
	fractal->zoomx *= 1.1;
	fractal->zoomy *= 1.1;
	fractal->shiftx += scale_nums(aux_x, -fractal->zoomx,
			fractal->zoomy, WIDTH) * 0.19;
	fractal->shifty += scale_nums(aux_y, fractal->zoomx,
			-fractal->zoomy, WIDTH) * 0.19;
}

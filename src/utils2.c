/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:11:29 by gdel-val          #+#    #+#             */
/*   Updated: 2024/07/01 23:11:31 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->img.img);
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_open);
	mlx_destroy_display(fractal->mlx_connect);
	free(fractal->mlx_connect);
	exit(0);
	return (0);
}

double	ft_atodbl2(char *str, double nb)
{
	double	dec;
	double	aux;

	dec = 10;
	while (*str >= '0' && *str <= '9')
	{
		nb = ((*str - '0') + (nb * 10));
		str++;
	}
	if (*str == '.')
	{
		dec = 10;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			aux = ((*str - '0'));
			nb = nb + (aux / dec);
			dec *= 10;
			str++;
		}
	}
	return (nb);
}

double	ft_atodbl(char *str, t_fractal *fractal)
{
	double	nb;
	int		sing;

	nb = 0;
	sing = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = 1;
		str++;
	}
	nb = ft_atodbl2(str, nb);
	if (*str < '0' || *str > '9')
		fractal->error = 1;
	if (sing == 1)
		nb = nb * -1;
	return (nb);
}

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.a = z1.a + z2.a;
	result.b = z1.b + z2.b;
	return (result);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.a = (z.a * z.a) - (z.b * z.b);
	result.b = 2 * z.a * z.b;
	return (result);
}

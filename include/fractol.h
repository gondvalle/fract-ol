/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:58:20 by gdel-val          #+#    #+#             */
/*   Updated: 2024/04/03 16:58:24 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <mlx.h>
# define WIDTH 500
# define HEIGHT 500

typedef struct s_complex
{
	double	a;
	double	b;
}				t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixel;
	int		color;
	int		end_line;
	int		line_length;
	int		rad;
	int		iter;
	
}				t_img;

typedef struct s_fractal
{
	char		*name;
	t_complex	num;
	t_img		img;
	void		*mlx_conect;
	void		*mlx_open;
}				t_fractal;

void	plot_start(t_fractal *fractal);
void	data_start(t_fractal *fractal);

#endif
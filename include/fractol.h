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
# include <stdint.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH 1200
# define HEIGHT 1200

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define MAGENTA 0xFF00FF
# define CYAN 0x00FFFF
# define VIOLET 0x8A2BE2
# define TURQUOISE 0x40E0D0
# define CORAL 0xFF7F50
# define EMERALD 0x2ECC71
# define SAPPHIRE 0x082567
# define AQUAMARINE 0x7FFFD4
# define PEACH 0xFFE5B4
# define RUBY 0xE0115F
# define TOPAZ 0x1E90FF
# define PALE_PINK 0xFFB6C1
# define FUCHSIA 0xFF00FF
# define CHARTREUSE 0x7FFF00
# define BRIGHT_TURQUOISE 0x00F5FF
# define AMARANTH 0xE52B50
# define LILAC 0xB666D2
# define NEON_YELLOW 0xDFFF00

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
	void		*mlx_connect;
	void		*mlx_open;
	int			color;
	int			iter;
	int			error;
	double		shiftx;
	double		shifty;
	double		zoomx;
	double		zoomy;
	double		julia_a;
	double		julia_b;
	double		zoom_ship;
}				t_fractal;

void		plot_start(t_fractal *fractal);
void		color_pixel(int x, int y, t_img *img, int color);
void		fractol_mandelbrot(int x, int y, t_fractal *fractal);
void		plot_render(t_fractal *fractal);
void		mlx_error(t_fractal *fractal);
double		scale_nums(double i, double sca_min, double sca_max, double max);
void		data_init(t_fractal *fractal);
void		zoom_in(t_fractal *fractal, int x, int y);
void		zoom_out(t_fractal *fractal, int x, int y);
void		buttons(t_fractal *fractal);
int			close_window(t_fractal *fractal);
double		ft_atodbl2(char *str, double nb);
double		ft_atodbl(char *str, t_fractal *fractal);
void		fractol_julia(int x, int y, t_fractal *fractal);
t_complex	complex_square(t_complex z);
t_complex	complex_sum(t_complex z1, t_complex z2);
void		fractol_four(int x, int y, t_fractal *fractal);

#endif
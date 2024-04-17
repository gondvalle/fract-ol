#include "/include/fractol.h"

void	mlx_error(t_fractal *fractal)
{
	if (fractal->mlx_open)
		mlx_destroy_window(fractal->mlx_conect, fractal->mlx_open);
	// if (fractal->mlx_conect)
	// {
	// 	mlx_destroy_display(fractal->mlx_conect);
	// 	free(fractal->mlx_conect);
	// }
	ft_putstr_fd("Error\n",2);
	exit(EXIT_FAILURE);
}
double	scale_nums(double i, double scale_min, double scale_max, double min, double max)
{
	double	sca;
	double	new_sca;
	double	resca;
	double	num;

	sca = max - min;
	new_sca = scale_max - scale_min;
	resca = new_sca / sca;
	num = scale_min + (i * resca);
	return (num);
}

// void	buttons(t_fractal *fractal)
// {
// 	mlx_hook(fractal->mlx_open, KeyPress, KeyPressMask, key_actions, fractal);
// 	mlx_hook(fractal->mlx_open, ButtonPress, ButtonPressMask, mouse_actions, fractal);
// 	mlx_hook(fractal->mlx_open, DestroyNotify, StructureNotifyMask, close_actions, fractal);
// }%
➜  test

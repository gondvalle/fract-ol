#include "/include/fractol.h"

void mlx_error(t_fracal *fractal)
{
	mlx_destroy_display(fractal->mlx_conect);
	ft_putstr("Error\n",2);
}

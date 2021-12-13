#include "headers/fractol.h"
#include "headers/libft.h"

int	frac_errors(int i)
{
	if (i == 1)
		 printf("usage: fractol [fractal name]\nFractal names:\n"
		"\t\t- Julia\n\t\t- Mandelbrot\n\t\t- Celtic_Mandelbrot\n");
	return (-1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
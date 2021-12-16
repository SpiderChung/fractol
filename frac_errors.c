#include "headers/fractol.h"
#include "headers/libft.h"

int	frac_errors(int i)
{
	if (i == 1)
		 printf("usage: fractol [fractal name]\nFractal names:\n"
		"\t\t- Julia\n\t\t- Mandelbrot\n\t\t- Celtic_Mandelbrot\n");
	return (-1);
}
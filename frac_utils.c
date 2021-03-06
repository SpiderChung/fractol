#include "headers/fractol.h"
#include "headers/libft.h"

int	ft_check_title(char *str)
{
	int size;


	size = ft_strlen(str);
	if (ft_strequal(str, "Mandelbrot"))
		return (1);
	if (ft_strequal(str, "Julia"))
		return (2);
	if (ft_strequal(str, "Celtic_Mandelbrot"))
		return (3);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	while (r > 255 && g > 255 && b > 255)
	{
		if (r > 255)
			r = r - 255;
		else if (g > 255)
			g = g - 255;
		else if (b > 255)
			b = b - 255;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_fractal(t_data *img, int dx, int dy, float dz)
{
	if (img->color == 20)
		img->color = 0;
	if (img->color == -1)
		img->color = 19;
	
	if (img->num_frac == 1)
		mandelbrot_set(img, dx, dy, dz);
	else if (img->num_frac == 2)
		julia_set(img, dx, dy, dz);
	else if (img->num_frac == 3)
		celtic_mandelbrot_set(img, dx, dy, dz);
}
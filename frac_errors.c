#include "headers/fractol.h"
#include "headers/libft.h"

int	frac_errors(int i)
{
	if (i == 1)
		 printf("usage: fractol [fractal name]\nFractal names:\n"
			"\t\t- Julia\n\t\t- Mandelbrot\n\t\t- Celtic_Mandelbrot\n");
	return (-1);
}

int	set_color(t_data *img, t_temp *temp)
{
	if (img->color == 0 || img->color == 10)
		return (create_trgb(0, temp->i * 2, temp->i * 3, temp->i * 5));
	else if (img->color == 1 || img->color == 11)
		return (create_trgb(0, temp->i * 3, temp->i * 5, temp->i * 2));
	else if (img->color == 2 || img->color == 12)
		return (create_trgb(0, temp->i * 12, temp->i * 3, temp->i * 5));
	else if (img->color == 3 || img->color == 13)
		return (create_trgb(0, temp->i * 5, temp->i * 2, temp->i * 5));
	else if (img->color == 4 || img->color == 14)
		return (create_trgb(0, temp->i * 5, temp->i * 5, temp->i * 10));
	else if (img->color == 5 || img->color == 15)
		return (create_trgb(0, temp->i * 2, temp->i * 5, temp->i * 20));
	else if (img->color == 6 || img->color == 16)
		return (create_trgb(0, temp->i * 5, temp->i * 8, temp->i * 13));
	else if (img->color == 7 || img->color == 17)
		return (create_trgb(0, temp->i * 8, temp->i * 13, temp->i * 5));
	else if (img->color == 8 || img->color == 18)
		return (create_trgb(0, temp->i * 13, temp->i * 5, temp->i * 8));
	else if (img->color == 9 || img->color == 19)
		return (create_trgb(0, temp->i * 89, temp->i * 144, temp->i * 233));
	else
		return (0);
}

int	set_color_center(t_data *img)
{
	if (img->color >= 0 && img->color < 10)
		return (create_trgb(0, 255, 255, 255));
	else
		return (create_trgb(0, 0, 0, 0));
}

void	set_init_param(t_data *img)
{
	img->canvas->max_x = WIN_WIDTH;
	img->canvas->max_y = WIN_HEIGHT;
	img->canvas->center_x = WIN_WIDTH / 2;
	img->canvas->center_y = WIN_HEIGHT / 2;
	//img.canvas->x = 1;
	//img.canvas->y = 1;
	if (img->num_frac == 2)
	{
		img->canvas->a = -0.75;
		img->canvas->b = -0.11;
	}
	if (img->num_frac == 3)
		img->canvas->zoom = 250;
	else
		img->canvas->zoom = 500;
}
#include "headers/fractol.h"
#include "headers/libft.h"

void	iter_xy_celtic(t_temp *temp)
{
	temp->temp_x = fabsf(temp->x * temp->x - temp->y * temp->y) + temp->x0;
	temp->temp_y = 2 * temp->x * temp->y + temp->y0;
	temp->x = temp->temp_x;
	temp->y = temp->temp_y;
	temp->z = temp->x * temp->x + temp->y * temp->y;
}

void	set_temp_celtic(t_data *img, t_temp *temp)
{
	temp->x0 = (img->canvas->x - img->canvas->center_x) / img->canvas->zoom;
	//temp->x0 = ((2 - (-2)) / (WIN_WIDTH - 0)) * (img->canvas->x - img->canvas->max_x) + 2;
 	temp->y0 = (img->canvas->y - img->canvas->center_y) / img->canvas->zoom;
	//temp->y0 = ((2 - (-2)) / (WIN_HEIGHT - 0)) * (img->canvas->y - img->canvas->max_y) + 2;
	//printf("------%f-------%f\n", temp->x0, temp->y0);
	temp->x = temp->x0;
	temp->y = temp->y0;
	temp->z = temp->x * temp->x + temp->y * temp->y;
	temp->iter = 100;
	img->canvas->iter = temp->iter;
	temp->i = 0;
	//temp->p = sqrt((temp->x - 0.25) * (temp->x - 0.25) + temp->y * temp->y);
	//temp->pc = 0.5 - (cos(atan2(temp->y, temp->x - 0.25)) / 2);
}

void	iter_celtic_mandelbrot(t_data *img)
{	
	t_temp	temp;

	set_temp_celtic(img, &temp);
	while (temp.i < temp.iter && temp.z < 4)
	{
		iter_xy_celtic(&temp);
		temp.i++;
	}
	if (temp.i == temp.iter)
		my_mlx_pixel_put(img, img->canvas->x, img->canvas->y,
			set_color_center(img));
	else
		my_mlx_pixel_put(img, img->canvas->x, img->canvas->y,
			set_color(img, &temp));
}

void	celtic_mandelbrot_set(t_data *img, int dx, int dy, float dz)
{
	if (dz != 0)
		img->canvas->zoom *= dz;
	img->canvas->center_x += dx;
	img->canvas->center_y += dy;
	img->canvas->x = 0;
	while (img->canvas->x < img->canvas->max_x)
	{
		img->canvas->y = 0;
		while (img->canvas->y < img->canvas->max_y)
		{
			iter_celtic_mandelbrot(img);
			img->canvas->y++;
		}	
		img->canvas->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	ft_menu(img);
}

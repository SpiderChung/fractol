#include "headers/fractol.h"
#include "headers/libft.h"

void	iter_xy_j(t_temp *temp)
{
	temp->temp_x = temp->x * temp->x - temp->y * temp->y + temp->x0;
	temp->temp_y = 2 * temp->x * temp->y + temp->y0;
	temp->x = temp->temp_x;
	temp->y = temp->temp_y;
	temp->z = temp->x * temp->x + temp->y * temp->y;
}

void	set_tmp_j(t_data *img, t_temp *temp)
{

	temp->x = (img->canvas->x - img->canvas->center_x) / img->canvas->zoom;
	temp->y = (img->canvas->y - img->canvas->center_y) / img->canvas->zoom;
	temp->x0 = img->canvas->a;
	temp->y0 = img->canvas->b;
	//temp->x0 = -0.75;
	//temp->y0 = 0.11;
	temp->z = temp->x * temp->x + temp->y * temp->y;
	temp->i = 0;
	temp->iter = img->canvas->iter;
}

void	iter_julia(t_data *img)
{
	t_temp	temp;

	set_tmp_j(img, &temp);
	while (temp.i < temp.iter && temp.z < 4)
	{
		iter_xy_j(&temp);
		temp.i++;
	}
	if (temp.i == temp.iter)
		my_mlx_pixel_put(img, img->canvas->x, img->canvas->y,
			set_color_center(img));
	else
		my_mlx_pixel_put(img, img->canvas->x, img->canvas->y,
			set_color(img, &temp));
}

void	julia_set(t_data *img, int dx, int dy, float dz)
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
			iter_julia(img);
			img->canvas->y++;
		}
		img->canvas->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	ft_menu(img);
}
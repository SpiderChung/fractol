#include "headers/fractol.h"
#include "headers/libft.h"


void	iter_xy(t_temp *temp)
{
	temp->temp_x = temp->x * temp->x - temp->y * temp->y + temp->x0;
	temp->temp_y = 2 * temp->x * temp->y + temp->y0;
	temp->x = temp->temp_x;
	temp->y = temp->temp_y;
	temp->z = temp->x * temp->x + temp->y * temp->y;
}

void	iter_mandelbrot(t_data *img)
{	
	t_temp	temp;

	temp.x0 = img->canvas->x - img->canvas->center_x;
	temp.y0 = img->canvas->y - img->canvas->center_y;
	temp.x = temp.x0;
	temp.y = temp.y0;
	temp.z = temp.x * temp.x + temp.y * temp.y;
	
	iter_xy(img);
}

void	mandelbrot_set(t_data *img)
{
	img->canvas->x = 0;
	while (img->canvas->x < img->canvas->max_x)
	{
		img->canvas->y = 0;
		while (img->canvas->y < img->canvas->max_y)
		{
			iter_mandelbrot(img);
			img->canvas->y++;
		}	
		img->canvas->x++;
	}
	my_mlx_pixel_put(img, img->canvas->x, img->canvas->y, 0x00FFFF00);
}

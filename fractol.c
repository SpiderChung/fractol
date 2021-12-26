/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:03:50 by schung            #+#    #+#             */
/*   Updated: 2021/12/21 20:57:36 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "headers/fractol.h"
#include "headers/libft.h"

void ft_menu(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win, 6, 6, 0x0000BFFF, "Fractol type: ");
	if (img->num_frac == 1)
		mlx_string_put(img->mlx, img->mlx_win, 150, 6, 0x0000BFFF,
			 "Mandelbrot");
	else if (img->num_frac == 2)
		mlx_string_put(img->mlx, img->mlx_win, 150, 6, 0x0000BFFF, "Julia");
	else if (img->num_frac == 3)
		mlx_string_put(img->mlx, img->mlx_win, 150, 6, 0x0000BFFF,
			 "Celtic Mandelbrot");
	mlx_string_put(img->mlx, img->mlx_win, 6, 36, 0x0000BFFF,
		 "Esc for exit");
	mlx_string_put(img->mlx, img->mlx_win, 6, 66, 0x0000BFFF,
		 "P for psychodelic");
	mlx_string_put(img->mlx, img->mlx_win, 6, 96, 0x0000BFFF,
		 "+/- for change color");
	mlx_string_put(img->mlx, img->mlx_win, 6, 126, 0x0000BFFF,
		 ft_strjoin("Iterations ", ft_itoa(img->canvas->iter)));
	if (img->num_frac == 2)
	{
		mlx_string_put(img->mlx, img->mlx_win, 6, 156, 0x0000BFFF,
			 ft_strjoin("a = ", ft_ftoa(img->canvas->a, 5)));
		mlx_string_put(img->mlx, img->mlx_win, 100, 156, 0x0000BFFF,
			 ft_strjoin("b = ", ft_ftoa(img->canvas->b, 5)));
	}
	printf("a = %f,   b = %f\n", img->canvas->a, img->canvas->b);

}

int	key_hook(int keycode, t_data *vars)
{
	printf("------%d -----", keycode);
	if (keycode == KEY_PLUS)
	{
		vars->color++;
		get_fractal(vars, 0, 0, 0);
	}
	else if (keycode == KEY_MINUS)
	{
		vars->color--;
		get_fractal(vars, 0, 0, 0);
	}
	else if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3)
	{	
		vars->num_frac = keycode - 17;
		set_init_param(vars);
		get_fractal(vars, 0, 0, 0);
	}
	else if (keycode == KEY_RIGHT)
		get_fractal(vars, -15, 0, 0);
	else if (keycode == KEY_LEFT)
		get_fractal(vars, 15, 0, 0);
	else if (keycode == KEY_UP)
		get_fractal(vars, 0, 15, 0);
	else if (keycode == KEY_DOWN)
		get_fractal(vars, 0, -15, 0);
	else if (keycode == KEY_TAB)
		vars->psycho *= (-1);
	
	return (0);
}

int hookl(t_data *vars)
{
	static int y;

	y++;
	printf("----%d----\n", y);
	if (vars->psycho == 1 && y == 120)
	{
		vars->color++;
		if (vars->color == 9)
			vars->color = 0;
		else if (vars->color == 19)
			vars->color = 10;
		get_fractal(vars, 0, 0, 0);
		y = 0;
	}
	else if (y == 120)
		y = 0;
	return (0);
}

int	mouse_hook(int mouse, int x, int y, t_data *vars)
{
	if (mouse == 4)
	{
		get_fractal(vars, ((float )x - vars->canvas->center_x)
			- ((float )x - vars->canvas->center_x) * 1.1,
			((float )y - vars->canvas->center_y)
			- ((float )y - vars->canvas->center_y) * 1.1, 1.1);
		vars->canvas->iter += 2;
	}
	else if (mouse == 5)
	{
		get_fractal(vars, ((float )x - vars->canvas->center_x)
			- ((float )x - vars->canvas->center_x) * 0.9,
			((float )y - vars->canvas->center_y)
			- ((float )y - vars->canvas->center_y) * 0.9, 0.9);
		vars->canvas->iter -= 2;
	}
	if (mouse == 1 && vars->num_frac == 2)
	{
		vars->canvas->a = ((float )x - vars->canvas->center_x) / (vars->canvas->zoom);
		vars->canvas->b = ((float )y - vars->canvas->center_y) / (vars->canvas->zoom);
		get_fractal(vars, 0, 0, 0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data		img;
	t_canvas 	canvas;

	img.canvas = &canvas;
	img.num_frac = ft_check_title(argv[1]);
	if (argc != 2 || !img.num_frac)
		return (frac_errors(1));
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		 &img.endian);
	set_init_param(&img);
	mlx_hook(img.mlx_win, 4, 1L << 2, mouse_hook, &img);
	//get_fractal(&img, 0, 0, 0);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop_hook(img.mlx, hookl, &img);
	mlx_loop(img.mlx);
	return (0);
}
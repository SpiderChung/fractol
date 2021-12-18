#include "headers/fractol.h"
#include "headers/libft.h"

int	key_hook(int keycode, t_data *vars)
{
	printf("Hello from key_hook! = %d +++++++ %d______%f\n", keycode, vars->num_frac, vars->canvas->max_x);
	if (keycode == KEY_PLUS)
	{
		vars->color++;
		if (vars->color == 20)
			vars->color = 0;
		mandelbrot_set(vars, 0, 0, 0);
	}
	else if (keycode == KEY_MINUS)
	{
		vars->color--;
		if (vars->color == -1)
			vars->color = 19;
		mandelbrot_set(vars, 0, 0, 0);
	}
	else if (keycode == KEY_ESC)
	{
		exit (0);
		//mlx_destroy_window(vars->mlx, vars->mlx_win);
	}
	return (0);
}

int	mouse_hook(int mouse, int x, int y, t_data *vars)
{

	printf("Hello from mouse_hook! = %d +++++++ %d x = %d  y = %d\n", mouse, vars->num_frac, x, y);
	if (mouse == 4)
	{
		mandelbrot_set(vars, ((float )x - vars->canvas->center_x)
			- ((float )x - vars->canvas->center_x) * 1.1,
			((float )y - vars->canvas->center_y)
			- ((float )y - vars->canvas->center_y) * 1.1, 1.1);
	}
	else if (mouse == 5)
	{
		mandelbrot_set(vars, ((float )x - vars->canvas->center_x)
			- ((float )x - vars->canvas->center_x) * 0.9,
			((float )y - vars->canvas->center_y)
			- ((float )y - vars->canvas->center_y) * 0.9, 0.9);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data		img;
	//t_canvas	canvas;

	img.canvas = (t_canvas *)malloc(sizeof(t_canvas));
	//img.canvas = NULL;
	img.num_frac = ft_check_title(argv[1]);
	if (argc != 2 || !img.num_frac)
		return (frac_errors(1));
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_hook(img.mlx_win, 4, 1L << 2, mouse_hook, &img);
	//mlx_hook(img.mlx_win, 5, 1L << 4, mouse_hook, &img);
	get_fractal(&img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
	//if (init_str(&str, argv[1]) == -1)
	//	return (1);
	//draw_str(str);
	return (0);
}
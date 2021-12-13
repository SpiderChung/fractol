#include "headers/fractol.h"
#include "headers/libft.h"


void	set_initial()
{

}

int	key_hook(int keycode, t_data *vars)
{
	printf("Hello from key_hook! = %d +++++++ %d\n", keycode, vars->endian);
	if (keycode == KEY_ESC)
	{
		exit (0);
		//mlx_destroy_window(vars->mlx, vars->mlx_win);
	}
	return (0);
}

int	mouse_hook_rs(int x, int y, t_data *vars)
{
	printf("Hello from mouse_hook_rs! = %d ++++++ x = %d  y = %d\n", vars->endian, x, y);
	return (0);
}


int	mouse_hook(int mouse, int x, int y, t_data *vars)
{
	mlx_hook(vars->mlx_win, 6, 1L << 6, mouse_hook_rs, vars);
	printf("Hello from mouse_hook! = %d +++++++ %d x = %d  y = %d\n", mouse, vars->endian, x, y);
	return (0);
}

int	ft_close(int keycode, t_data *vars)
{
	static int i = 0;

	i = keycode;
	printf("Hello from key_hook! = %d\n", i);
	my_mlx_pixel_put(vars, 10, 10, 0x00FFFF00);
	//mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("qqq");
	return (0);
}

int main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2 || !ft_check_title(argv[1]))
		return (frac_errors(1));
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FFFF00);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	//mlx_hook(img.mlx_win, 4, 1L << 2, mouse_hook, &img);
	//mlx_hook(img.mlx_win, 5, 1L << 4, mouse_hook, &img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
	//if (init_str(&str, argv[1]) == -1)
	//	return (1);
	//draw_str(str);
	return (0);
}
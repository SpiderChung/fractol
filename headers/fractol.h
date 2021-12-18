/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:45 by schung            #+#    #+#             */
/*   Updated: 2021/12/18 17:27:45 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <pthread.h>

# define WIN_WIDTH 1620
# define WIN_HEIGHT 1080

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_MINUS 27

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_canvas
{
	float	x;
	float	y;
	float	max_x;
	float	max_y;
	float	center_x;
	float	center_y;
	float	zoom;
}	t_canvas;

typedef struct s_temp
{
	float	x0;
	float	y0;
	float	temp_x;
	float	temp_y;
	float	temp_z;
	float	x;
	float	y;
	float	z;
	float	c;
	float	p;
	float	pc;
	int		iter;
	int		i;
}	t_temp;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_canvas	*canvas;
	int			num_frac;
	int			color;
}	t_data;

/*________frac_errors.c__________*/
int		frac_errors(int i);
int		set_color(t_data *img, t_temp *temp);
int		set_color_center(t_data *img);

/*________frac_utils.c__________*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		ft_check_title(char *str);
void	get_fractal(t_data *img);

/*________mandelbrot.c__________*/
void	mandelbrot_set(t_data *img, int dx, int dy, float dz);
void	iter_mandelbrot(t_data *img);
void	iter_xy(t_temp *temp);

/*________julia.c__________*/
void	julia_set(t_data *img);

/*________celtic_mandelbrot.c__________*/
void	celtic_mandelbrot_set(t_data *img);

#endif
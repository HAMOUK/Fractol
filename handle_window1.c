/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:32:47 by hlongin           #+#    #+#             */
/*   Updated: 2025/07/07 02:01:09 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	exit(EXIT_SUCCESS);
}


static void	apply_zoom(t_fractol *f, double zoom_factor)
{
	double center_re = (f->x_max + f->x_min) / 2.0;
	double center_im = (f->y_max + f->y_min) / 2.0;

	f->x_min = center_re + (f->x_min - center_re) * zoom_factor;
	f->x_max = center_re + (f->x_max - center_re) * zoom_factor;
	f->y_min = center_im + (f->y_min - center_im) * zoom_factor;
	f->y_max = center_im + (f->y_max - center_im) * zoom_factor;

	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);

	if (f->fractal_type == MANDELBROT)
		draw_mandelbrot(f);
	else if (f->fractal_type == JULIA)
		draw_julia(f);
	else if (f->fractal_type == BURNING_SHIP)
		draw_burning_ship(f);
}

static void	apply_palette(t_fractol *f, int palette_key)
{
	if (palette_key == KEY_1)
		f->palette = 1;
	else if (palette_key == KEY_2)
		f->palette = 2;
	else if (palette_key == KEY_3)
		f->palette = 3;
	else if (palette_key == KEY_4)
		f->palette = 4;

	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);

	if (f->fractal_type == MANDELBROT)
		draw_mandelbrot(f);
	else if (f->fractal_type == JULIA)
		draw_julia(f);
	else if (f->fractal_type == BURNING_SHIP)
		draw_burning_ship(f);
}

int	handle_key(int keycode, t_fractol *f)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		close_program(f);
	else if (keycode == 24)
		apply_zoom(f, 0.9);
	else if (keycode == 27)
		apply_zoom(f, 1.1);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 || keycode == KEY_4)
		apply_palette(f, keycode);
	return (0);
}

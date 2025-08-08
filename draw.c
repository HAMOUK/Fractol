/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:11:27 by hlongin           #+#    #+#             */
/*   Updated: 2025/07/07 01:48:48 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		i;
	int		max_iter;

	max_iter = 100;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
			ci = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;
			i = mandelbrot_iterations(cr, ci, max_iter);
			if (i == max_iter)
				put_pixel(f, x, y, 0x000000);
			else
				put_pixel(f, x, y, color_shift(i, max_iter, f->palette));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	draw_julia(t_fractol *f)
{
	int		x;
	int		y;
	double	zr;
	double	zi;
	int		i;
	int		max_iter;
	double	cr;
	double	ci;

	cr = -0.7;
	ci = 0.27015;
	max_iter = 100;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zr = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
			zi = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;
			i = julia_iterations(zr, zi, cr, ci, max_iter);
			if (i == max_iter)
				put_pixel(f, x, y, 0x000000);
			else
				put_pixel(f, x, y, color_shift(i, max_iter, f->palette));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	draw_burning_ship(t_fractol *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		i;
	int		max_iter;

	max_iter = 100;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
			ci = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;
			i = burning_ship_iterations(cr, ci, max_iter);
			if (i == max_iter)
				put_pixel(f, x, y, 0x000000);
			else
				put_pixel(f, x, y, color_shift(i, max_iter, f->palette));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

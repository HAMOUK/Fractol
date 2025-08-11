/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:12:06 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/12 00:50:39 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot_pixel(t_fractol *f, int x, int y)
{
	double	cr;
	double	ci;
	int		iterations;

	cr = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
	ci = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;
	iterations = mandelbrot_iterations(cr, ci, 100);
	if (iterations == 100)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, color_shift(iterations, 100, f->palette));
}

void	calculate_julia_pixel(t_fractol *f, int x, int y)
{
	double			zr;
	double			zi;
	t_julia_params	par;
	int				iterations;

	par.cr = f->julia_cr;
	par.ci = f->julia_ci;
	par.max_iter = 100;
	zr = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
	zi = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;
	iterations = julia_iterations(zr, zi, par);
	if (iterations == par.max_iter)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, color_shift(iterations, par.max_iter, f->palette));
}

void	calculate_burning_ship_pixel(t_fractol *f, int x, int y)
{
	double	cr;
	double	ci;
	int		iterations;

	cr = f->x_min + x * (f->x_max - f->x_min) / WIDTH;
	ci = f->y_min + y * (f->y_max - f->y_min) / HEIGHT;
	iterations = burning_ship_iterations(cr, ci, 100);
	if (iterations == 100)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, color_shift(iterations, 100, f->palette));
}

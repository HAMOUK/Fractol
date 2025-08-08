/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 01:34:30 by hlongin           #+#    #+#             */
/*   Updated: 2025/07/07 01:39:27 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	julia_iterations(double zr, double zi, double cr, double ci, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (zr * zr + zi * zi <= 4 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	burning_ship_iterations(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = fabs(2 * zr * zi) + ci;
		zr = fabs(tmp);
		i++;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:27:30 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 23:41:53 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	palette1(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	palette2(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * t);
	g = (int)(128 * t);
	b = (int)(255 * (1 - t));
	return ((r << 16) | (g << 8) | b);
}

static int	palette3(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * pow(t, 0.5));
	g = (int)(255 * pow(1 - t, 1.5));
	b = (int)(128 + 127 * sin(t * 6.28));
	return ((r << 16) | (g << 8) | b);
}

int	color_shift(int i, int max_iter, int palette)
{
	double	t;
	int		v;

	if (i == max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	if (palette == 1)
		return (palette1(t));
	else if (palette == 2)
		return (palette2(t));
	else if (palette == 3)
		return (palette3(t));
	else
	{
		v = (int)(t * 255);
		return ((v << 16) | (v << 8) | v);
	}
}

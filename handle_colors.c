/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:27:30 by hlongin           #+#    #+#             */
/*   Updated: 2025/07/07 01:58:26 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hsv_to_rgb(double h, double s, double v)
{
	double	c = v * s;
	double	x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	double	m = v - c;
	double	r, g, b;

	h = fmod(h, 360.0);

	if (h < 60) {
		r = c; g = x; b = 0;
	} else if (h < 120) {
		r = x; g = c; b = 0;
	} else if (h < 180) {
		r = 0; g = c; b = x;
	} else if (h < 240) {
		r = 0; g = x; b = c;
	} else if (h < 300) {
		r = x; g = 0; b = c;
	} else {
		r = c; g = 0; b = x;
	}

	int R = (int)((r + m) * 255);
	int G = (int)((g + m) * 255);
	int B = (int)((b + m) * 255);
	return ((R << 16) | (G << 8) | B);
}


static int	palette1(double t)
{
	int	r = (int)(9 * (1 - t) * t * t * t * 255);
	int	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	palette2(double t)
{
	int	r = (int)(255 * t);
	int	g = (int)(128 * t);
	int	b = (int)(255 * (1 - t));
	return ((r << 16) | (g << 8) | b);
}

static int	palette3(double t)
{
	int	r = (int)(255 * pow(t, 0.5));
	int	g = (int)(255 * pow(1 - t, 1.5));
	int	b = (int)(128 + 127 * sin(t * 6.28));
	return ((r << 16) | (g << 8) | b);
}

static int	palette4(int i, int max_iter)
{
	double	hue = 360.0 * ((double)i / max_iter);
	double	sat = 1.0;
	double	val = (i < max_iter) ? 1.0 : 0.0;
	return (hsv_to_rgb(hue, sat, val));
}

int	color_shift(int i, int max_iter, int palette)
{
	double	t;

	if (i == max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	if (palette == 1)
		return (palette1(t));
	else if (palette == 2)
		return (palette2(t));
	else if (palette == 3)
		return (palette3(t));
	else if (palette == 4)
		return (palette4(i, max_iter));
	else
	{
		int v = (int)(t * 255);
		return ((v << 16) | (v << 8) | v);
	}
}

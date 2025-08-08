/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:45:18 by hlongin           #+#    #+#             */
/*   Updated: 2025/07/07 02:05:04 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start_fractal(t_fractol *f, int fractal_id)
{
	if (fractal_id == 1)
	{
		init_window(f);
		f->fractal_type = MANDELBROT;
		draw_mandelbrot(f);
	}
	else if (fractal_id == 2)
	{
		init_window_julia(f);
		f->fractal_type = JULIA;
		draw_julia(f);
	}
	else if (fractal_id == 3)
	{
		init_window(f);
		f->fractal_type = BURNING_SHIP;
		draw_burning_ship(f);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	f;
	int			fractal_id;

	if (argc == 2)
		fractal_id = check_args(argv[1]);
	else
	{
		ft_printf("Usage: ./fractol mandelbrot | julia\n");
		exit(EXIT_FAILURE);
	}
	start_fractal(&f, fractal_id);
	mlx_loop(f.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:45:18 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/12 00:48:35 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia_params(t_fractol *f, int argc, char **argv)
{
	if (argc >= 4)
	{
		f->julia_cr = atof(argv[2]);
		f->julia_ci = atof(argv[3]);
	}
	else
	{
		f->julia_cr = -0.7;
		f->julia_ci = 0.27015;
	}
}

void	start_fractal(t_fractol *f, int fractal_id, int argc, char **argv)
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
		init_julia_params(f, argc, argv);
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

	if (argc >= 2)
		fractal_id = check_args(argv[1]);
	else
	{
		ft_printf("Usage: ./fractol mandelbrot | julia\n | burning_ship\n");
		exit(EXIT_FAILURE);
	}
	start_fractal(&f, fractal_id, argc, argv);
	mlx_loop(f.mlx);
	return (0);
}

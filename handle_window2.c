/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 01:36:28 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 23:42:12 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window_julia(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_printf("Erreur : échec de mlx_init\n");
		exit(EXIT_FAILURE);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length,
			&f->endian);
	mlx_hook(f->win, 17, 0, close_program, f);
	mlx_key_hook(f->win, handle_key, f);
	f->x_min = -2.0;
	f->x_max = 2.0;
	f->y_min = -2.0;
	f->y_max = 2.0;
	f->palette = 1;
}

void	init_window(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_printf("Erreur : échec de mlx_init\n");
		exit(EXIT_FAILURE);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length,
			&f->endian);
	mlx_hook(f->win, 17, 0, close_program, f);
	mlx_key_hook(f->win, handle_key, f);
	f->x_min = -2.0;
	f->x_max = -1.7;
	f->y_min = -0.1;
	f->y_max = 0.1;
	f->palette = 1;
}

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*pixel;

	pixel = f->img_addr + (y * f->line_length + x * (f->bpp / 8));
	*(unsigned int *)pixel = color;
}

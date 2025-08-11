/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:45:41 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/12 00:30:04 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// === Window Dimensions ===
# define WIDTH 1500
# define HEIGHT 900

// === Fractal Types ===
# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

// === Keycodes ===
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20

// === Standard Libraries ===
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// === Project Libraries ===
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"

// === Structures ===
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		fractal_type;
	double	julia_cr;
	double	julia_ci;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		palette;
}			t_fractol;

typedef struct s_julia_params
{
	double	cr;
	double	ci;
	int		max_iter;
}	t_julia_params;

// === Initialization ===
void		init_window(t_fractol *f);
void		init_window_julia(t_fractol *f);

// === Drawing ===
void		calculate_mandelbrot_pixel(t_fractol *f, int x, int y);
void		calculate_julia_pixel(t_fractol *f, int x, int y);
void		calculate_burning_ship_pixel(t_fractol *f, int x, int y);
void		draw_mandelbrot(t_fractol *f);
void		draw_julia(t_fractol *f);
void		draw_burning_ship(t_fractol *f);
void		put_pixel(t_fractol *f, int x, int y, int color);

// === Iteration Functions ===
int			mandelbrot_iterations(double cr, double ci, int max_iter);
int			julia_iterations(double zr, double zi, t_julia_params params);
int			burning_ship_iterations(double cr, double ci, int max_iter);

// === Input Handling ===
int			handle_key(int keycode, t_fractol *f);
int			check_args(char *argv);

// === Utility ===
int			color_shift(int i, int max_iter, int palette);
int			close_program(t_fractol *f);

#endif
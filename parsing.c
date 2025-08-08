/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:48:40 by hlongin           #+#    #+#             */
/*   Updated: 2025/07/07 00:58:06 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(char *arg)
{
	if (!ft_strncmp(arg, "mandelbrot", 11))
	{
		return (1);
	}
	else if (!ft_strncmp(arg, "julia", 6))
		return (2);
	else if (!ft_strncmp(arg, "burning_ship", 13))
		return (3);
	else
	{
		ft_printf("Fractale inconnue : %s\n", arg);
		ft_printf("Fractales disponibles : mandelbrot | julia\n");
		exit(EXIT_FAILURE);
	}
}

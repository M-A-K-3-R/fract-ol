/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:52:37 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/06 21:52:39 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit (0);
	return (0);
}

int	key_esc(int keycode, t_data *var)
{
	if (keycode == 53)
		ft_close(var);
	return (0);
}

void	ft_zoom_n_dezoom(t_data *var)
{
	if (var->fractal == 0)
		ft_mandelbrot(var);
	else if (var->fractal == 1)
		ft_julia(var);
}

int	mouse_hook(int keycode, int x, int y, t_data *var)
{
	if (keycode == 5)
	{
		var->i *= 1.8;
		x = var->o_x;
		y = var->o_y;
		if (var->i >= 3000 && var->max_iter <= 700)
			var->max_iter += 10;
		ft_zoom_n_dezoom(var);
	}
	if (keycode == 4)
	{
		var->i *= 0.5;
		x = var->o_x;
		y = var->o_y;
		if (var->i >= 3000 && var->max_iter <= 700)
			var->max_iter -= 10;
		ft_zoom_n_dezoom(var);
	}
	return (0);
}

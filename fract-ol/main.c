/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:38 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/06 01:49:40 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write (1, str++, 1);
}

void	origine(t_data *var, int x, int y)
{
	var->o_x = x / 2;
	var->o_y = y / 2;
}

void	ft_mlx(t_data *var, char **av)
{
	var->mlx = mlx_init();
	var->img = mlx_new_image(var->mlx, W, H);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
	var->mlx_win = mlx_new_window(var->mlx, W, H, av[1]);
	origine(var, W, H);
	if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
	{
		var->max_iter = 100;
		var->i = W / 4;
		var->fractal = 0;
		ft_mandelbrot(var);
	}
	else if (ft_strncmp(av[1], "Julia", 6) == 0)
	{
		var->max_iter = 100;
		var->i = W / 4;
		var->fractal = 1;
		var->set = ft_strdup(av[2]);
		ft_julia(var);
	}
}

int	main(int ac, char **av)
{
	t_data	var;

	if (ac >= 2)
	{
		if ((ft_strncmp(av[1], "Mandelbrot", 11) != 0
				&& ft_strncmp(av[1], "Julia", 6) != 0) || ac > 3)
		{
			ft_putstr("you have to choose between \"Mandelbrot\" or \"Julia\"\n");
			ft_putstr("if you choose \"Julia\" => julia set: +0.285 +0.01i\n");
			return (0);
		}
		ft_mlx(&var, av);
		mlx_hook(var.mlx_win, 17, 0, ft_close, &var);
		mlx_hook(var.mlx_win, 2, 0, key_esc, &var);
		mlx_mouse_hook(var.mlx_win, mouse_hook, &var);
		mlx_loop(var.mlx);
	}
	else
	{
		ft_putstr("you have to choose between \"Mandelbrot\" or \"Julia\"\n");
		ft_putstr("if you choose \"Julia\" => julia set: +0.285 +0.01i\n");
	}
	return (0);
}

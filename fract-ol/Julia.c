/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:10:33 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/06 22:10:34 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double	ft_atoi_my_version(const char *str)
{
	int		i;
	int		j;
	double	signe;
	double	nbr;

	i = 0;
	signe = 1.0;
	nbr = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1.0;
		i++;
	}
	j = i;
	while ((str[j] >= '0' && str[j] <= '9') || str[j] == '.')
	{
		if (str[j] != '.')
			nbr = nbr * 10.0 + str[j] - 48.0;
		j++;
	}
	nbr = nbr / pow(10.0, j - 3);
	return (nbr * signe);
}

void	check_set(t_data *var)
{
	if (var->set == NULL)
	{
		var->c_x = -0.70176;
		var->c_y = -0.3842;
	}
	else if (var->set)
	{
		var->c = ft_split(var->set, ' ');
		var->c_x = ft_atoi_my_version(var->c[0]);
		var->c_y = ft_atoi_my_version(var->c[1]);
	}
}

void	ft_julia(t_data *var)
{
	check_set(var);
	var->y = -2.0 * (H / 4);
	while (var->y <= 2.0 * (H / 4))
	{
		var->x = -2.0 * (W / 4);
		while (var->x <= 2.0 * (H / 4))
		{
			var->z_x = var->x / var->i;
			var->z_y = var->y / var->i;
			var->iter = 0;
			ft_calc(var);
			var->x++;
		}
		var->y++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
}

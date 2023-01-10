/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:48:44 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/06 21:48:47 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc(t_data *var)
{
	t_colors	clrs;

	while (pow(var->z_x, 2) + pow(var->z_y, 2) <= 4.0
		&& var->iter < var->max_iter)
	{
		var->save = var->z_x;
		var->z_x = pow(var->z_x, 2) - pow(var->z_y, 2) + var->c_x;
		var->z_y = 2 * var->save * var->z_y + var->c_y;
		var->iter++;
	}
	if (var->iter == var->max_iter)
		my_mlx_pixel_put(var, var->o_x + var->x, var->o_y - var->y, 0);
	else
	{
		clrs.red = sin(var->iter / 50.0) * (127 + 90);
		clrs.green = sin(var->iter / 40.0) * (127 + 90);
		clrs.blue = sin(var->iter / 30.0) * (127 + 90);
		clrs.color = clrs.red << 16 | clrs.green << 8 | clrs.blue;
		my_mlx_pixel_put(var, var->o_x + var->x, var->o_y - var->y, clrs.color);
	}
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (i < n)
	{
		if (string1[i] != string2[i] || string1[i] == 0)
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < W && y < H)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

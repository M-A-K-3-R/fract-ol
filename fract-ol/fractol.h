/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farctol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:06:24 by haouadia          #+#    #+#             */
/*   Updated: 2022/12/24 15:06:27 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W 1000
# define H 1000
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct colors
{
	int	red ;
	int	green;
	int	blue;
	int	color;
}	t_colors;

typedef struct variables
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			x;
	double			y;
	double			o_x;
	double			o_y;
	double			i;
	double			save;
	unsigned int	iter;
	unsigned int	max_iter;
	double			z_x;
	double			z_y;
	double			c_x;
	double			c_y;
	int				fractal;
	char			*set;
	char			**c;
}	t_data;

int		ft_close(t_data *var);
int		key_esc(int keycode, t_data *var);
int		mouse_hook(int keycode, int x, int y, t_data *var);
void	ft_mandelbrot(t_data *var);
void	ft_julia(t_data *var);
void	ft_mlx(t_data *var, char **av);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	origine(t_data	*var, int x, int y);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
void	ft_calc(t_data *var);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
int		number_of_word(char const *s1, char c);
void	word_malloc(char **splited, char const *s1, char c, int nw);
void	free_func(char **splited, int i);
void	check_set(t_data *var);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
double	ft_atoi_my_version(const char *str);

#endif
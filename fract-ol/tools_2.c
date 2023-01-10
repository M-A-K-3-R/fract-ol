/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 04:14:16 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/09 04:14:18 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[start] && i < len)
	{
		dup[i] = s[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_func(char **splited, int i)
{
	while (i--)
		free (splited[i]);
	free (splited);
}

void	word_malloc(char **splited, char const *s1, char c, int nw)
{
	int		i;
	int		start;
	size_t	len;

	i = -1;
	start = 0;
	while (++i < nw)
	{
		len = 0;
		while (s1[start] && s1[start] == c)
			start++;
		while (s1[start] && s1[start] != c)
		{
			start++;
			len++;
		}
		splited[i] = ft_substr(s1, start - len, len);
		if (!splited[i])
			free_func(splited, i);
	}
}

int	number_of_word(char const *s1, char c)
{
	int	i;
	int	nbr_s;

	i = 0;
	nbr_s = 0;
	while (s1[i])
	{
		if (s1[i] != c)
		{
			nbr_s++;
			while (s1[i] && s1[i] != c)
				i++;
		}
		if (s1[i])
			i++;
	}
	return (nbr_s);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (NULL);
	splited = malloc(sizeof(char *) * (number_of_word(s, c) + 1));
	if (!(splited))
		return (0);
	word_malloc(splited, s, c, number_of_word(s, c));
	splited[number_of_word(s, c)] = NULL;
	return (splited);
}

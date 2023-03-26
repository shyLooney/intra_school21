/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:49:35 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/23 14:19:15 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!*s)
		return (0);
	while (*(s + 1))
	{
		if (*s != c && *(s + 1) == c)
			counter++;
		s++;
	}
	if (*s != c)
		counter++;
	return (counter);
}

static int	search_index_noc(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) == c)
		i++;
	return (i);
}

static int	search_index_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	clear_str(char **str, int rows)
{
	int	counter;

	counter = 0;
	while (counter < rows)
	{
		free(*(str + counter));
		counter++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = count_words(s, c);
	j = 0;
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		s = s + search_index_noc(s, c);
		*(str + j) = ft_substr(s, 0, search_index_c(s, c));
		if (!str[j++])
		{
			clear_str(str, j);
			return (NULL);
		}
		s = s + search_index_c(s, c);
	}
	*(str + j) = 0;
	return (str);
}

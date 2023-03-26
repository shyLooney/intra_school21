/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:39:55 by dmacmill          #+#    #+#             */
/*   Updated: 2021/12/12 15:03:30 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	int		counter;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	counter = 0;
	str = (char *) malloc(len_1 + len_2 + 1);
	if (str == 0)
		return (0);
	while (len_2 + len_1 > counter)
	{
		if (counter < len_1)
			*(str + counter) = *(s1 + counter);
		else
			*(str + counter) = *(s2 + counter - len_1);
		counter++;
	}
	*(str + counter) = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*(s + counter))
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	size_t	counter;
	size_t	len;
	char	*arr;

	counter = 0;
	len = 0;
	while (*(s1 + len))
		len++;
	arr = (char *) malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (*(s1 + counter))
	{
		*(arr + counter) = *(s1 + counter);
		counter++;
	}
	*(arr + counter) = 0;
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (*(s + i + start) && (i < len))
	{
		*(str + i) = *(s + (size_t)start + i);
		i++;
	}
	*(str + i) = 0;
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	counter;

	counter = 0;
	p = malloc(count * size);
	if (!p)
		return (0);
	while (counter < count * size)
	{
		*(char *)(p + counter) = 0;
		counter++;
	}
	return (p);
}

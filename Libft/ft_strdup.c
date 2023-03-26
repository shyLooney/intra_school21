/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:26:10 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 12:50:54 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

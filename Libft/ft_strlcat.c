/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:21:07 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/23 14:08:27 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dst + i) && i < dstsize)
		i++;
	while (*(src + j) && j + i + 1 < dstsize)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (j > 0)
		*(dst + i + j) = 0;
	return (i + ft_strlen(src));
}

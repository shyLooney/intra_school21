/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:26:17 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 14:10:40 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	while (*(src + counter) && counter < dstsize)
	{
		*(dst + counter) = *(src + counter);
		counter++;
	}
	if (counter >= dstsize)
		*(dst + dstsize - 1) = 0;
	else
		*(dst + counter) = 0;
	while (*(src + counter))
		counter++;
	return (counter);
}

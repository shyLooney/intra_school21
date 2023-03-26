/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:57 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 15:52:43 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!n || (!dst && !src))
		return (dst);
	if (dst < src)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		n--;
		while (n > 0)
		{
			*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
			n--;
		}
		if (n == 0)
			*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
	}
	return (dst);
}

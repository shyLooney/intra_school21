/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:26:31 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 15:04:31 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)(haystack));
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(needle + j) && *(haystack + i + j) == *(needle + j))
			j++;
		if (!(*(needle + j)) && j + i <= len)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

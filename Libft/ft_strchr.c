/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:26:05 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 20:06:20 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	if (*(s + counter) == c)
		return ((char *)(s + counter));
	while (*(s + counter))
	{
		counter++;
		if (*(s + counter) == c)
			return ((char *)(s + counter));
	}
	return (0);
}

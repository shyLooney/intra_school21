/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:26:35 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 20:06:51 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;
	int	info;

	info = -1;
	counter = 0;
	if (*(s + counter) == c)
		info = counter;
	while (*(s + counter))
	{
		counter++;
		if (*(s + counter) == c)
			info = counter;
	}
	if (info > -1)
		return ((char *)(s + info));
	else
		return (0);
}

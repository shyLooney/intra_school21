/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:24:50 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/15 17:25:14 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

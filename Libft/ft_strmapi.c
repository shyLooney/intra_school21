/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:34:55 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 18:46:43 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				counter;

	counter = 0;
	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	while (*(s + counter))
	{
		*(str + counter) = f(counter, *(str + counter));
		counter++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:39:43 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/22 14:50:52 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

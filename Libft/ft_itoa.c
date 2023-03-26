/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:13:33 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/22 12:33:01 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_digit(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	negative(char **str, int *n)
{
	char	*p;

	p = *str;
	**str = '-';
	if (*n == -2147483648)
	{
		*(n) = *n + 1000000000;
		*(p + 1) = '2';
	}
	*n = (*n) * (-1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = len_digit(n);
	str = (char *) malloc(len + 1);
	if (!str)
		return (0);
	*(str + len) = 0;
	len--;
	if (n < 0)
		negative(&str, &n);
	if (n == 0)
		*str = '0';
	while ((len > 0 && *(str + 1) != '2') || (*(str + 1) == '2' && len > 1)
		|| (*str != '-' && len > -1))
	{
		*(str + len) = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (str);
}

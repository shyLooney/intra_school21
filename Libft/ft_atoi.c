/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:24:27 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 20:05:39 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	number;

	number = 0;
	sign = -1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = 1;
		str++;
	}
	if (count_number(str) >= 19 && sign == 1)
		return (0);
	if (count_number(str) >= 19 && sign == -1)
		return (-1);
	while (*str && *str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return ((-1) * sign * number);
}

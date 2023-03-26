/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:12:51 by dmacmill          #+#    #+#             */
/*   Updated: 2021/10/16 19:24:12 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	ditoa(int n, int i)
{
	int	ten;
	int	counter;

	ten = 1;
	counter = i;
	while (i > 1)
	{
		ten *= 10;
		i--;
	}
	return ((n / ten % 10) + '0');
}

static void	negative(int *n, int fd, int *counter)
{
	write(fd, "-", 1);
	if (*n == -2147483648)
	{
		*(n) = *n + 2000000000;
		write(fd, "2", 1);
		(*counter)--;
	}
	*n = (*n) * (-1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		counter;
	int		number;
	char	c;

	counter = count_digit(n);
	if (n < 0)
		negative(&n, fd, &counter);
	if (n == 0)
		write(fd, "0", 1);
	number = n;
	while (n > 0)
	{
		n /= 10;
		c = ditoa(number, counter);
		write(fd, &c, 1);
		counter--;
	}
}

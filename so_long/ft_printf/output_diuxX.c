/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_diuxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:03:00 by dmacmill          #+#    #+#             */
/*   Updated: 2021/12/15 13:07:40 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_d2(int *num, int *count)
{
	if (*num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	if (*num == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (*num < 0)
	{
		*num = -(*num);
		write(1, "-", 1);
		(*count)++;
	}
}

void	output_d(va_list ap, int *count)
{
	int		num;
	char	str[20];
	int		i;

	i = 0;
	num = va_arg(ap, int);
	output_d2(&num, count);
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, str + i--, 1);
		(*count)++;
	}
}

void	output_u(va_list ap, int *count)
{
	unsigned int	num;
	char			str[20];
	int				i;

	i = 0;
	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, str + i--, 1);
		(*count)++;
	}
}

void	output_x(va_list ap, int *count)
{
	char			*str;
	char			new_str[25];
	unsigned int	num;
	int				i;

	i = 0;
	num = va_arg(ap, unsigned int);
	str = "0123456789abcdef";
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (num > 0)
	{
		new_str[i++] = str[num % 16];
		num /= 16;
	}
	i--;
	while (i >= 0)
	{
		write(1, new_str + i--, 1);
		(*count)++;
	}
}

void	output_hx(va_list ap, int *count)
{
	char			*str;
	char			new_str[25];
	unsigned int	num;
	int				i;

	i = 0;
	num = va_arg(ap, unsigned int);
	str = "0123456789ABCDEF";
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (num > 0)
	{
		new_str[i++] = str[num % 16];
		num /= 16;
	}
	i--;
	while (i >= 0)
	{
		write(1, new_str + i--, 1);
		(*count)++;
	}
}

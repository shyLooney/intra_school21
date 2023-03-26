/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:03:18 by dmacmill          #+#    #+#             */
/*   Updated: 2021/12/16 19:18:10 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	found_percent(const char *str, va_list ap, int *count)
{
	if (*str == 'c')
		output_c(ap, count);
	else if (*str == 's')
		output_s(ap, count);
	else if (*str == 'p')
		output_p(ap, count);
	else if (*str == 'd')
		output_d(ap, count);
	else if (*str == 'i')
		output_d(ap, count);
	else if (*str == 'u')
		output_u(ap, count);
	else if (*str == 'x')
		output_x(ap, count);
	else if (*str == 'X')
		output_hx(ap, count);
	else
		*count = -1;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			found_percent(str + i++ + 1, ap, &count);
		else
		{
			write(1, str + i, 1);
			count++;
		}
		if (str[i] == '%')
			i++;
		i++;
		if (count == -1)
			return (count);
	}
	va_end(ap);
	return (count);
}

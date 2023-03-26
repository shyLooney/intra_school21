/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:02:54 by dmacmill          #+#    #+#             */
/*   Updated: 2021/12/16 17:06:12 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_c(va_list ap, int *count)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	(*count)++;
}

void	output_s(va_list ap, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*(str + i))
	{
		write(1, str + i, 1);
		(*count)++;
		i++;
	}
}

int	output_p2(unsigned long int p, int *count)
{
	if (p == 0)
	{
		write(1, "0x0", 3);
		*count += 3;
		return (1);
	}
	return (0);
}

void	output_p(va_list ap, int *count)
{
	char				*alph;
	char				adr[30];
	unsigned long int	p;
	int					i;

	i = 0;
	p = va_arg(ap, unsigned long int);
	alph = "0123456789abcdef";
	if (output_p2(p, count))
		return ;
	while (p > 0)
	{
		adr[i++] = alph[p % 16];
		p /= 16;
	}
	i--;
	write(1, "0x", 2);
	*count += 2;
	while (i >= 0)
	{
		write(1, adr + i--, 1);
		(*count)++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:03:10 by dmacmill          #+#    #+#             */
/*   Updated: 2021/12/16 18:03:43 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	output_c(va_list ap, int *count);
void	output_s(va_list ap, int *count);
void	output_p(va_list ap, int *count);
void	output_d(va_list ap, int *count);
void	output_u(va_list ap, int *count);
void	output_x(va_list ap, int *count);
void	output_hx(va_list ap, int *count);
int		ft_printf(const char *str, ...);

#endif
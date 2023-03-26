/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:29:40 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/28 15:22:56 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_nwatoi(char *str, int *arr)
{
	long int	num;
	int			i;
	int			sign;

	i = -1;
	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		num = -num;
		i++;
	}
	if (*str == '+')
		i++;
	if (strlen_num(str) > 11)
		ft_error(NULL, arr);
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
		num = str[i] - '0' + num * 10;
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		ft_error(NULL, arr);
	return (sign * num);
}

void	ft_duplicate(int *arr, int len)
{
	int	i;
	int	j;
	int	info;

	i = 0;
	j = 0;
	info = 1;
	while (i < len)
	{
		while (j < len)
		{
			if (arr[i] == arr[j] && i != j)
				info = 0;
			j++;
		}
		i++;
		j = 0;
	}
	if (!info)
		ft_error(NULL, arr);
}

void	ft_sort_arr(int *arr, int *new_arr, int len)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while ((++i) < len)
		new_arr[i] = arr[i];
	i = 0;
	while (i < (len - 1))
	{
		while (j < (len - 1))
		{
			if (new_arr[j] > new_arr[j + 1])
				ft_swap(&new_arr[j], &new_arr[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_wrlst(t_all **all, int *arr, int len)
{
	int	*new_arr;

	new_arr = malloc(sizeof(int) * len);
	if (!new_arr)
		ft_error(NULL, arr);
	ft_sort_arr(arr, new_arr, len);
	if (ft_createlst(all) == -1 || ft_initstack(all, arr, new_arr, len) == -1)
		ft_error(all, arr);
	free(new_arr);
}

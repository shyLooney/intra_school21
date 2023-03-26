/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:24:13 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 15:16:22 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_all **all, int *arr)
{
	if (arr)
		free(arr);
	if (all && *all)
	{
		ft_error_clr(all);
		free(*all);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_check_str(int argc, char *ar[])
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (i < argc)
	{
		if (!only_space(ar[i]))
			return (-1);
		while (ar[i][++j])
		{
			if ((ar[i][j] == '-' || ar[i][j] == '+') && (!(ar[i][j + 1] >= '0'
				&& ar[i][j + 1] <= '9')))
				return (-1);
			if (!((ar[i][j] >= '0' && ar[i][j] <= '9') || ar[i][j] == '-'
				|| ar[i][j] == '+' || ar[i][j] == ' ' || ar[i][j] == '	'))
				return (-1);
			if (j != 0 && (ar[i][j] == '-' || ar[i][j] == '+')
				&& !(ar[i][j - 1] == ' ' || ar[i][j - 1] == '	'))
				return (-1);
		}
		i++;
		j = -1;
	}
	return (1);
}

int	*ft_cpyarr(int *arr, int len)
{
	int	i;
	int	*new_arr;

	i = 0;
	new_arr = malloc(sizeof(int) * (len + 1));
	if (!new_arr)
		ft_error(NULL, arr);
	while (i < len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	free(arr);
	return (new_arr);
}

int	*ft_create_arr(int *arr, char *argv, int *len)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		while (argv[j] == ' ' || argv[j] == '	')
			j++;
		if (!argv[j])
			break ;
		arr = ft_cpyarr(arr, *len);
		arr[*len] = ft_nwatoi(argv + j, arr);
		(*len)++;
		if (argv[j] == '-' || argv[j] == '+')
			j++;
		while (argv[j] >= '0' && argv[j] <= '9')
			j++;
	}
	return (arr);
}

int	*ft_parser(int argc, char *argv[], t_all **all)
{
	int	i;
	int	len;
	int	*arr;

	i = 1;
	len = 0;
	arr = NULL;
	if (ft_check_str(argc, argv) == -1)
		ft_error(NULL, NULL);
	while (i < argc)
	{
		arr = ft_create_arr(arr, argv[i], &len);
		i++;
	}
	if (len == 1)
	{
		free(arr);
		exit(0);
	}
	ft_duplicate(arr, len);
	ft_wrlst(all, arr, len);
	free(arr);
	return (0);
}

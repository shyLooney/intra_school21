/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:37 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 14:55:42 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_map(t_all *all, int i)
{
	int	j;
	int	info;

	j = all->map.size.y - 1;
	info = 0;
	if (j + 1 != i)
		info = 1;
	while (j != i && info)
	{
		free(all->map.mtrx[j]);
		j--;
	}
	if (info)
		free(all->map.mtrx);
	ft_error("Incorrect map\n");
}

void	free_map(t_all *all)
{
	int	j;

	j = 0;
	while (j < all->map.size.y)
	{
		free(all->map.mtrx[j]);
		j++;
	}
	free(all->map.mtrx);
}

void	exit_game(t_all *all)
{
	free_map(all);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:56 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 14:40:10 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	fire_count(t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < all->map.size.y)
	{
		while (j < all->map.size.x)
		{
			if (all->map.mtrx[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

int	press_key(int key, t_all *all)
{
	if (key == 53)
	{
		exit_game(all);
	}
	else
	{
		move(key, all);
	}
	load_map(all);
	return (0);
}

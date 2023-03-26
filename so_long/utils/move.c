/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:49 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 14:30:25 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(t_all *all)
{
	if (all->map.mtrx[all->img.pos.y][all->img.pos.x - 1] == 'E' &&
		fire_count(all) == 0)
		exit_game(all);
	if (all->map.mtrx[all->img.pos.y][all->img.pos.x - 1] != '1' &&
		all->map.mtrx[all->img.pos.y][all->img.pos.x - 1] != 'E')
	{
		all->map.mtrx[all->img.pos.y][all->img.pos.x - 1] = 'P';
		all->map.mtrx[all->img.pos.y][all->img.pos.x] = '0';
		all->step++;
		ft_printf("Number of steps: %d\n", all->step);
	}
}

void	move_right(t_all *all)
{
	if (all->map.mtrx[all->img.pos.y][all->img.pos.x + 1] == 'E' &&
		fire_count(all) == 0)
		exit_game(all);
	if (all->map.mtrx[all->img.pos.y][all->img.pos.x + 1] != '1' &&
		all->map.mtrx[all->img.pos.y][all->img.pos.x + 1] != 'E')
	{
		all->map.mtrx[all->img.pos.y][all->img.pos.x + 1] = 'P';
		all->map.mtrx[all->img.pos.y][all->img.pos.x] = '0';
		all->step++;
		ft_printf("Number of steps: %d\n", all->step);
	}
}

void	move_up(t_all *all)
{
	if (all->map.mtrx[all->img.pos.y + 1][all->img.pos.x] == 'E' &&
		fire_count(all) == 0)
		exit_game(all);
	if (all->map.mtrx[all->img.pos.y + 1][all->img.pos.x] != '1' &&
		all->map.mtrx[all->img.pos.y + 1][all->img.pos.x] != 'E')
	{
		all->map.mtrx[all->img.pos.y + 1][all->img.pos.x] = 'P';
		all->map.mtrx[all->img.pos.y][all->img.pos.x] = '0';
		all->step++;
		ft_printf("Number of steps: %d\n", all->step);
	}
}

void	move_down(t_all *all)
{
	if (all->map.mtrx[all->img.pos.y - 1][all->img.pos.x] == 'E' &&
		fire_count(all) == 0)
		exit_game(all);
	if (all->map.mtrx[all->img.pos.y - 1][all->img.pos.x] != '1' &&
		all->map.mtrx[all->img.pos.y - 1][all->img.pos.x] != 'E')
	{
		all->map.mtrx[all->img.pos.y - 1][all->img.pos.x] = 'P';
		all->map.mtrx[all->img.pos.y][all->img.pos.x] = '0';
		all->step++;
		ft_printf("Number of steps: %d\n", all->step);
	}
}

void	move(int key, t_all *all)
{
	if (key == 0)
		move_left(all);
	else if (key == 2)
		move_right(all);
	else if (key == 1)
		move_up(all);
	else if (key == 13)
		move_down(all);
	else
		return ;
}

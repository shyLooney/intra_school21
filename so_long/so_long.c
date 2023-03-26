/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:18:01 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 14:40:21 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_other(t_all *all)
{
	all->step = 0;
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->map.size.x * WIDTH,
			all->map.size.y * HEIGHT, "So long");
}

int	close_window(t_all *all)
{
	exit_game(all);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_all	all;

	check_args(argc, argv);
	init_map(&all, argv[1]);
	init_other(&all);
	load_map(&all);
	mlx_hook(all.win, 2, 1L << 0, press_key, &all);
	mlx_hook(all.win, 17, 1L << 0, close_window, &all);
	mlx_loop(all.mlx);
	return (0);
}

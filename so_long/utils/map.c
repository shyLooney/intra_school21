/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:45 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 14:19:57 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	add_img(t_all *all, int row, int col)
{
	if (all->map.mtrx[row][col] == '1')
		all->img.img_ptr = mlx_xpm_file_to_image(all->mlx, "./img/wall.xpm",
				&all->img.size.x, &all->img.size.y);
	else if (all->map.mtrx[row][col] == '0')
		all->img.img_ptr = mlx_xpm_file_to_image(all->mlx, "./img/ground.xpm",
				&all->img.size.x, &all->img.size.y);
	else if (all->map.mtrx[row][col] == 'C')
		all->img.img_ptr = mlx_xpm_file_to_image(all->mlx, "./img/fire.xpm",
				&all->img.size.x, &all->img.size.y);
	else if (all->map.mtrx[row][col] == 'E')
		all->img.img_ptr = mlx_xpm_file_to_image(all->mlx, "./img/exit.xpm",
				&all->img.size.x, &all->img.size.y);
	else if (all->map.mtrx[row][col] == 'P')
	{
		all->img.img_ptr = mlx_xpm_file_to_image(all->mlx, "./img/person.xpm",
				&all->img.size.x, &all->img.size.y);
		all->img.pos.x = col;
		all->img.pos.y = row;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img_ptr,
		WIDTH * col, HEIGHT * row);
	mlx_destroy_image(all->mlx, all->img.img_ptr);
	return (0);
}

int	load_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->map.size.y)
	{
		while (j < all->map.size.x)
		{
			add_img(all, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

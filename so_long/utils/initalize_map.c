/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:40 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 14:19:16 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	malc_mtrx(t_all *all)
{
	int	i;

	i = all->map.size.y;
	all->map.mtrx = malloc(sizeof(char *) * i);
	if (!all->map.mtrx)
		error_map(all, all->map.size.y);
	while (--i >= 0)
	{
		all->map.mtrx[i] = malloc(sizeof(char) * (all->map.size.x + 1));
		if (!all->map.mtrx[i])
			error_map(all, i);
	}
}

void	calc_size(t_all *all, char *argv)
{
	int		fd;
	char	*str;
	int		i;
	int		j;

	i = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Incorrect file\n");
	str = get_next_line(fd);
	j = ft_strlenn(str);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	all->map.size.y = i - 1;
	all->map.size.x = j;
}

void	wr_data_2(t_all *all, int *i, int *j, char *str)
{
	while (str[*j] && str[*j] != '\n')
	{
		all->map.mtrx[*i][*j] = str[*j];
		(*j)++;
	}
}

void	wr_data(t_all *all, char *argv)
{
	int		fd;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_map(all, -1);
	str = get_next_line(fd);
	while (str)
	{
		wr_data_2(all, &i, &j, str);
		all->map.mtrx[i][j] = 0;
		i++;
		j = 0;
		free(str);
		str = get_next_line(fd);
	}
	if (i != all->map.size.y)
		error_map(all, -1);
	close(fd);
}

void	init_map(t_all *all, char *argv)
{
	calc_size(all, argv);
	malc_mtrx(all);
	wr_data(all, argv);
}

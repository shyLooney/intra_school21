/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:18:09 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 16:09:45 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include "ft_printf/ft_printf.h"

# define HEIGHT 64
# define WIDTH 64

typedef struct s_crd
{
	int	x;
	int	y;
}	t_crd;

typedef struct s_img
{
	void	*img_ptr;
	t_crd	size;
	t_crd	pos;
}	t_img;

typedef struct s_map
{
	char	**mtrx;
	t_crd	size;
}	t_map;

typedef struct s_all
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		step;
}	t_all;

int		ft_strlenn(char *str);
void	check_args(int argc, char *argv[]);
int		check_map(int fd);
int		check_pec(char *str);
void	ft_error(char *str);
void	init_map(t_all *all, char *argv);
void	free_map(t_all *all);
void	error_map(t_all *all, int i);
int		load_map(t_all *all);
int		press_key(int key, t_all *all);
void	move(int key, t_all *all);
int		fire_count(t_all *all);
void	exit_game(t_all *all);

#endif

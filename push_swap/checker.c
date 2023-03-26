/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:01:51 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 15:14:32 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_act_2(char *str, t_all *all)
{
	int	len;

	len = ft_strlen(str);
	if (len == 2 && str[0] == 'r' && str[1] == 'a')
		ft_ra(all, 0);
	else if (len == 2 && str[0] == 'r' && str[1] == 'b')
		ft_rb(all, 0);
	else if (len == 2 && str[0] == 'r' && str[1] == 'r')
		ft_rr(all, 0);
	else if (len == 2 && str[0] == 'p' && str[1] == 'a')
		ft_pa(all, 0);
	else if (len == 2 && str[0] == 'p' && str[1] == 'b')
		ft_pb(all, 0);
	else
		return (0);
	return (1);
}

int	read_act(char *str, t_all *all)
{
	int	len;
	int	info;

	len = ft_strlen(str);
	info = 1;
	if (len == 2 && str[0] == 's' && str[1] == 'a')
		ft_sa(all, 0);
	else if (len == 2 && str[0] == 's' && str[1] == 'b')
		ft_sb(all, 0);
	else if (len == 2 && str[0] == 's' && str[1] == 's')
		ft_ss(all, 0);
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rra(all, 0);
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rrb(all, 0);
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(all, 0);
	else
		info = 0;
	if (read_act_2(str, all) == 0 && info == 0)
		return (0);
	else
		return (1);
}

int	main(int argc, char *argv[])
{
	t_all	*all;
	char	*str;
	int		info;

	ft_parser(argc, argv, &all);
	str = get_next_line(0);
	while (str)
	{
		info = read_act(str, all);
		free(str);
		if (info == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		str = get_next_line(0);
	}
	if (ft_sorted(all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_clear(all);
	return (0);
}

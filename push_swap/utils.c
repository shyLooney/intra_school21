/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:52:39 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 15:17:15 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strlen_num(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && str[i] >= '0' && str[i] <= 9)
		i++;
	return (i);
}

int	ft_sorted(t_all *all)
{
	t_node	*beg;
	int		info;

	beg = all->stack_a;
	info = 1;
	if (all->stack_b != NULL)
		return (0);
	while (beg)
	{
		if (info != beg->order)
			return (0);
		info++;
		beg = beg->next;
	}
	return (1);
}

void	found_next(t_all *all, int stack)
{
	int	mid;

	mid = (all->mid + all->next) / 2;
	all->next++;
	if (stack)
		ft_pa(all, 1);
	all->stack_a->flag_a = -1;
	if (all->stack_b && all->stack_b->order != all->next)
		ft_rr(all, 1);
	else
		ft_ra(all, 1);
}

int	only_space(char *str)
{
	int	i;
	int	info;

	i = 0;
	info = 0;
	if (!str)
		return (0);
	while (str[i] && !info)
	{
		if (str[i] >= '0' && str[i] <= '9')
			info = 1;
		i++;
	}
	if (info)
		return (1);
	else
		return (0);
}

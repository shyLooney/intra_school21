/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faster2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:44:10 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 15:10:26 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_min(t_all *all, t_node *elem)
{
	t_node	*beg;
	int		num;

	beg = all->stack_a;
	num = all->max;
	while (beg)
	{
		if (elem->order < beg->order && num > beg->order)
			num = beg->order;
		beg = beg->next;
	}
	return (num);
}

t_node	*next_elem(t_all *all)
{
	t_node	*beg;
	int		min;
	int		i;

	beg = all->stack_b;
	i = 0;
	min = 10000;
	while (beg)
	{
		if (beg->flag_a + beg->flag_b < min)
			min = beg->flag_a + beg->flag_b;
		beg = beg->next;
	}
	beg = all->stack_b;
	while (beg->flag_a + beg->flag_b != min)
		beg = beg->next;
	return (beg);
}

int	check_stack_b(t_all *all)
{
	while (!all->stack_b && all->stack_a->order != 1)
		ft_ra(all, 1);
	return (0);
}

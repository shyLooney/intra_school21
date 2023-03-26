/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:51:59 by dmacmill          #+#    #+#             */
/*   Updated: 2022/03/27 15:52:00 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_all *all)
{
	ft_sa(all, 1);
}

void	ft_sort_three(t_all *all)
{
	if (all->stack_a->order == 1 && all->stack_a->next->order == 3)
	{
		ft_rra(all, 1);
		ft_sa(all, 1);
	}
	else if (all->stack_a->order == 3 && all->stack_a->next->order == 2)
	{
		ft_ra(all, 1);
		ft_sa(all, 1);
	}
	else if (all->stack_a->order == 3 && all->stack_a->next->order == 1)
	{
		ft_ra(all, 1);
	}
	else if (all->stack_a->order == 2 && all->stack_a->next->order == 3)
		ft_rra(all, 1);
	else if (all->stack_a->order == 2 && all->stack_a->next->order == 1)
		ft_sa(all, 1);
}

void	ft_sort_four(t_all *all)
{
	t_node	*beg;

	beg = all->stack_a;
	while (beg->next && beg->order != 4)
	{
		beg = beg->next;
		ft_ra(all, 1);
	}
	ft_pb(all, 1);
	ft_sort_three(all);
	ft_pa(all, 1);
	ft_ra(all, 1);
}

void	ft_sort_five(t_all *all, int info)
{
	t_node	*beg;

	beg = all->stack_a;
	while (beg->next && info)
	{
		if (beg->order == 5 || beg->order == 4)
		{
			beg = beg->next;
			ft_pb(all, 1);
			info--;
		}
		else
		{
			beg = beg->next;
			ft_ra(all, 1);
		}
	}
	ft_sort_three(all);
	if (all->stack_b->order > all->stack_b->next->order)
		ft_rb(all, 1);
	ft_pa(all, 1);
	ft_ra(all, 1);
	ft_pa(all, 1);
	ft_ra(all, 1);
}

void	small_sort(t_all *all)
{
	int		i;
	t_node	*beg;

	beg = all->stack_a;
	i = 0;
	while (beg)
	{
		beg = beg->next;
		i++;
	}
	if (i == 2)
		ft_sort_two(all);
	else if (i == 3)
		ft_sort_three(all);
	else if (i == 4)
		ft_sort_four(all);
	else
		ft_sort_five(all, 2);
}

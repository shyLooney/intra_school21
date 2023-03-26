/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:42:35 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/30 17:52:38 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_node *a)
{
	int		i;

	i = 0;
	if (!a)
		return (0);
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_clean_stack(t_all *all)
{
	t_node	*beg;

	beg = all->stack_b;
	while (beg)
	{
		found_next(all, 1);
		beg = beg->next;
	}
}

void	ft_stack_three(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_b->order;
	b = all->stack_b->next->order;
	c = all->stack_b->next->next->order;
	if (a < b && a + 2 == b && a < c)
	{
		ft_rrb(all, 1);
		ft_sb(all, 1);
	}
	else if (a > b && a - 1 == b && a > c)
	{
		ft_rb(all, 1);
		ft_sb(all, 1);
	}
	else if (a > b && a - 2 == b && a > c)
		ft_rb(all, 1);
	else if (a < b && a + 1 == b && c < a)
		ft_rrb(all, 1);
	else if (a > b && a - 1 == b && a < c)
		ft_sb(all, 1);
}

void	ft_stack_two(t_all *all)
{
	int	a;
	int	b;

	a = all->stack_b->order;
	b = all->stack_b->next->order;
	if (a > b)
		ft_sb(all, 1);
}

void	few_stack(t_all *all)
{
	int	i;

	if (!all->stack_b)
		return ;
	i = len_stack(all->stack_b);
	if (i == 2)
		ft_stack_two(all);
	if (i == 3)
		ft_stack_three(all);
	else
		return ;
	ft_clean_stack(all);
}

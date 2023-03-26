/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:41:15 by dmacmill          #+#    #+#             */
/*   Updated: 2022/03/27 15:41:23 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_all *all, int info)
{
	t_node	*last;

	if (!all->stack_a || !all->stack_a->next)
		return ;
	last = all->stack_a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	all->stack_a->prev = last;
	last->next = all->stack_a;
	last->prev = NULL;
	all->stack_a = last;
	if (info)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_all *all, int info)
{
	t_node	*last;

	if (!all->stack_b)
		return ;
	if (!all->stack_b->next)
		return ;
	last = all->stack_b;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	all->stack_b->prev = last;
	last->next = all->stack_b;
	last->prev = NULL;
	all->stack_b = last;
	if (info)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_all *all, int info)
{
	ft_rra(all, 0);
	ft_rrb(all, 0);
	if (info)
		write(1, "rrr\n", 4);
}

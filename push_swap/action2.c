/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:42:20 by dmacmill          #+#    #+#             */
/*   Updated: 2022/03/27 15:42:24 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_all *all, int info)
{
	t_node	*first;
	t_node	*last;

	if (!all->stack_a || !all->stack_a->next)
		return ;
	last = all->stack_a;
	first = last;
	while (last->next)
		last = last->next;
	last->next = first;
	all->stack_a = all->stack_a->next;
	all->stack_a->prev = NULL;
	first->prev = last;
	first->next = NULL;
	if (info)
		write(1, "ra\n", 3);
}

void	ft_rb(t_all *all, int info)
{
	t_node	*first;
	t_node	*last;

	if (!all->stack_b || !all->stack_b->next)
		return ;
	last = all->stack_b;
	first = last;
	while (last->next)
		last = last->next;
	last->next = first;
	all->stack_b = all->stack_b->next;
	all->stack_b->prev = NULL;
	first->prev = last;
	first->next = NULL;
	if (info)
		write(1, "rb\n", 3);
}

void	ft_rr(t_all *all, int info)
{
	ft_ra(all, 0);
	ft_rb(all, 0);
	if (info)
		write(1, "rr\n", 3);
}

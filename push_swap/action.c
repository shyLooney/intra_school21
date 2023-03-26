/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:40:10 by dmacmill          #+#    #+#             */
/*   Updated: 2022/03/27 15:41:03 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_all *all, int info)
{
	t_node	*elem;

	if (!all->stack_a || !all->stack_a->next)
		return ;
	elem = all->stack_a;
	if (all->stack_a->next->next)
		all->stack_a->next->next->prev = elem;
	all->stack_a = all->stack_a->next;
	elem->next = all->stack_a->next;
	elem->prev = all->stack_a;
	all->stack_a->next = elem;
	all->stack_a->prev = NULL;
	if (info)
		write(1, "sa\n", 3);
}

void	ft_sb(t_all *all, int info)
{
	t_node	*elem;

	if (!all->stack_b || !all->stack_b->next)
		return ;
	elem = all->stack_b;
	if (all->stack_b->next->next)
		all->stack_b->next->next->prev = elem;
	all->stack_b = all->stack_b->next;
	elem->next = all->stack_b->next;
	elem->prev = all->stack_b;
	all->stack_b->next = elem;
	all->stack_b->prev = NULL;
	if (info)
		write(1, "sb\n", 3);
}

void	ft_ss(t_all *all, int info)
{
	ft_sa(all, 0);
	ft_sb(all, 0);
	if (info)
		write(1, "ss\n", 3);
}

void	ft_pb(t_all *all, int info)
{
	t_node	*elem;

	if (!all->stack_a)
		return ;
	elem = all->stack_a;
	all->stack_a = all->stack_a->next;
	if (elem->next)
		elem->next->prev = NULL;
	elem->next = all->stack_b;
	if (all->stack_b)
		all->stack_b->prev = elem;
	all->stack_b = elem;
	if (info)
		write(1, "pb\n", 3);
}

void	ft_pa(t_all *all, int info)
{
	t_node	*elem;

	if (!all->stack_b)
		return ;
	elem = all->stack_b;
	all->stack_b = all->stack_b->next;
	if (elem->next)
		elem->next->prev = NULL;
	elem->next = all->stack_a;
	if (all->stack_a)
		all->stack_a->prev = elem;
	all->stack_a = elem;
	if (info)
		write(1, "pa\n", 3);
}

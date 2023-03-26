/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:45:48 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 15:15:59 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_flag_a(t_all *all, t_node *elem)
{
	t_node	*beg;
	int		i;
	int		num;

	beg = all->stack_a;
	i = 0;
	num = new_min(all, elem);
	while (beg && beg->order != num)
	{
		beg = beg->next;
		i++;
	}
	if (i < len_stack(all->stack_a) - i)
	{
		elem->value_a = 0;
		elem->flag_a = i;
	}
	else
	{
		elem->value_a = 1;
		elem->flag_a = len_stack(all->stack_a) - i;
	}
}

void	calculate_flag_b(t_all *all, t_node *beg)
{
	int	i;

	i = 1;
	beg->flag_b = 0;
	while (beg->next)
	{
		beg->next->flag_b = i;
		beg->value_b = 0;
		beg = beg->next;
		i++;
	}
	i = 1;
	while (beg)
	{
		if (beg->flag_b > i)
		{
			beg->flag_b = i;
			beg->value_b = 1;
		}
		calculate_flag_a(all, beg);
		beg = beg->prev;
		i++;
	}
}

void	first_push_b(t_all *all)
{
	int	i;

	i = len_stack(all->stack_a);
	while (i > 2)
	{
		if (all->stack_a->order != all->max && all->stack_a->order != all->next)
		{
			if (all->stack_a->order > all->mid)
			{
				i--;
				ft_pb(all, 1);
				ft_rb(all, 1);
			}
			else
			{
				i--;
				ft_pb(all, 1);
			}
		}
		else
			ft_ra(all, 1);
	}
}

void	main_algorithm(t_all *all)
{
	t_node	*elem;
	int		i;

	elem = next_elem(all);
	i = 0;
	while (i < elem->flag_a)
	{
		if (elem->value_a)
			ft_rra(all, 1);
		else
			ft_ra(all, 1);
		i++;
	}
	i = 0;
	while (i < elem->flag_b)
	{
		if (elem->value_b)
			ft_rrb(all, 1);
		else
			ft_rb(all, 1);
		i++;
	}
	ft_pa(all, 1);
}

void	main_sort(t_all *all)
{
	int		i;
	t_node	*beg;

	i = 0;
	beg = all->stack_a;
	while (beg)
	{
		beg = beg->next;
		i++;
	}
	if (i <= 5)
	{
		small_sort(all);
		return ;
	}
	first_push_b(all);
	if (all->stack_a->order == all->next)
		ft_ra(all, 1);
	while (!ft_sorted(all))
	{
		calculate_flag_b(all, all->stack_b);
		main_algorithm(all);
		check_stack_b(all);
	}
}

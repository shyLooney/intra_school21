/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:24:18 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/30 21:41:41 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_error_clr(t_all **all)
{
	t_node	*elem;
	t_node	*begin;

	begin = (*all)->stack_a;
	while (begin)
	{
		elem = begin;
		begin = begin->next;
		free(elem);
	}
	begin = (*all)->stack_b;
	while (begin)
	{
		elem = begin;
		begin = begin->next;
		free(elem);
	}
}

int	ft_createlst(t_all **all)
{
	*all = malloc(sizeof(t_all));
	if (!*all)
		return (-1);
	(*all)->stack_b = NULL;
	(*all)->stack_a = NULL;
	(*all)->flag = 0;
	return (0);
}

int	ft_listnew(t_all **all, t_node **begin, int order, int value)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (-1);
	elem->order = order;
	elem->next = NULL;
	elem->prev = NULL;
	if (*begin)
	{
		elem->prev = *begin;
		(*begin)->next = elem;
		(*begin) = (*begin)->next;
	}
	else
	{
		*begin = elem;
		(*all)->stack_a = *begin;
	}
	return (1);
}

int	ft_initstack(t_all **all, int *arr, int *new_arr, int len)
{
	int		i;
	int		j;
	t_node	*begin;

	i = 0;
	j = 0;
	begin = NULL;
	(*all)->max = len;
	(*all)->next = 1;
	(*all)->mid = len / 2 + 1;
	while (i < len)
	{
		while (j < len)
		{
			if (arr[i] == new_arr[j])
				ft_listnew(all, &begin, j + 1, arr[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

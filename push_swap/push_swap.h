/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:24:23 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 15:17:02 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_node
{
	int				order;
	int				value_a;
	int				value_b;
	int				flag_a;
	int				flag_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_all
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		next;
	int		max;
	int		mid;
	int		flag;
}	t_all;

int		ft_strlen(char *str);
int		strlen_num(char *str);
int		*ft_parser(int argc, char *argv[], t_all **all);
void	ft_error(t_all **all, int *arr);
void	ft_duplicate(int *arr, int len);
int		ft_nwatoi(char *str, int *arr);
void	ft_wrlst(t_all **all, int *arr, int len);
int		ft_createlst(t_all **all);
void	ft_error_clr(t_all **all);
int		ft_initstack(t_all **all, int *arr, int *new_arr, int len);
void	ft_sa(t_all *all, int info);
void	ft_sb(t_all *all, int info);
void	ft_ss(t_all *all, int info);
void	ft_pb(t_all *all, int info);
void	ft_pa(t_all *all, int info);
void	ft_ra(t_all *all, int info);
void	ft_rb(t_all *all, int info);
void	ft_rr(t_all *all, int info);
void	ft_rra(t_all *all, int info);
void	ft_rrb(t_all *all, int info);
void	ft_rrr(t_all *all, int info);
void	main_sort(t_all *all);
void	ft_clear(t_all *all);
void	small_sort(t_all *all);
int		count_top(t_all *all);
void	few_stack(t_all *all);
void	found_next(t_all *all, int stack);
int		len_stack(t_node *a);
int		ft_sorted(t_all *all);
int		new_min(t_all *all, t_node *elem);
t_node	*next_elem(t_all *all);
int		check_stack_b(t_all *all);
int		only_space(char *str);

#endif
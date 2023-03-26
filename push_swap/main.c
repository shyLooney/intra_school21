/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:45:22 by dmacmill          #+#    #+#             */
/*   Updated: 2022/07/01 14:58:58 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_all	*all;

	if (argc < 2)
		return (0);
	ft_parser(argc, argv, &all);
	if (ft_sorted(all))
	{
		ft_clear(all);
		return (0);
	}
	main_sort(all);
	ft_clear(all);
	return (0);
}

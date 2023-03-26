/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:27 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 16:47:38 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_pec2(char *str, int *arr)
{
	while (*str)
	{
		if (*str == 'P')
			arr[0]++;
		else if (*str == 'E')
			arr[1]++;
		else if (*str == 'C')
			arr[2]++;
		str++;
	}
}

int	check_pec(char *argv)
{
	int		arr[3];
	int		fd;
	char	*str;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Incorrect file\n");
	str = get_next_line(fd);
	while (str)
	{
		check_pec2(str, arr);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
		return (1);
	return (0);
}

int	top_line(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	if (i != len)
		return (0);
	return (1);
}

int	mid_line(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (i == 0 && str[i] != '1')
			return (0);
		if (str[i] != '1' && str[i] != '0' && str[i] != 'E' && str[i] != 'P'
			&& str[i] != 'C')
			return (0);
		i++;
	}
	if (str[i - 1] != '1' || i != len)
		return (0);
	return (1);
}

int	check_map(int fd)
{
	char	*str;
	char	*str_cp;
	int		len;

	str = get_next_line(fd);
	len = ft_strlenn(str);
	if (!str || !top_line(str, len))
		return (0);
	while (str)
	{
		str_cp = str;
		str = get_next_line(fd);
		if ((str == NULL && !top_line(str_cp, len))
			|| (str != NULL && !mid_line(str, len)))
		{
			free(str_cp);
			free(str);
			return (0);
		}
		free(str_cp);
	}
	return (1);
}

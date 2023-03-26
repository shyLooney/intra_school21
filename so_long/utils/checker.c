/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:31 by dmacmill          #+#    #+#             */
/*   Updated: 2022/04/30 16:48:45 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	write(0, "Error\n", 6);
	ft_printf("%s", str);
	exit(1);
}

int	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strstr(char *str, char *substr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i + j] && substr[j] && str[i + j] == substr[j])
			j++;
		if ((int)ft_strlen(substr) == j && !str[i + j] && !substr[j])
			return (1);
		i++;
		j = 0;
	}
	return (0);
}

void	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc != 2 || (argc == 2 && !ft_strstr(argv[1], ".ber")))
		ft_error("Incorrect argument\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Incorrect file\n");
	if (!check_map(fd))
		ft_error("Incorrect map\n");
	close(fd);
	if (!check_pec(argv[1]))
		ft_error("Add P or E or C\n");
}

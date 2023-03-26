/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:07:26 by dmacmill          #+#    #+#             */
/*   Updated: 2021/12/12 14:01:28 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

void	clear_str(char **buffer)
{
	char	*str;
	char	*buf;
	int		len;
	int		i;

	len = 0;
	i = 0;
	buf = *buffer;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i] == '\n')
		i++;
	while (buf[len])
		len++;
	str = ft_substr(*buffer, i, len);
	free(*buffer);
	*buffer = str;
}

int	read_file(int fd, char **buffer)
{
	int		read_symb;
	char	*str;
	char	*p;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (check_line(str) == -1)
	{
		read_symb = read(fd, str, BUFFER_SIZE);
		if (read_symb <= 0)
		{
			free(str);
			return (-1);
		}
		str[read_symb] = '\0';
		p = ft_strjoin(*buffer, str);
		free(*buffer);
		*buffer = p;
	}
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char) * 1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = 0;
	}
	else
		clear_str(&buffer[fd]);
	read_file(fd, &buffer[fd]);
	if (buffer[fd][0] == 0)
	{
		free(buffer[fd]);
		buffer[fd] = 0;
		return (NULL);
	}
	else
		str = ft_substr(buffer[fd], 0, check_line(buffer[fd]));
	return (str);
}

/*#include <stdio.h>
int main()
{
	int a = open("big_line_no_nl", O_RDONLY);
	int b = open("123", O_RDONLY);
	//printf("a before open: %d\n", a);
	//char *str = ft_calloc (sizeof(char),(BUFFER_SIZE + 1));
	char *str;
	//a = read(a, str, BUFFER_SIZE);
	//printf("a = %d\nstring: %s\n", a, str);
	for (int i = 0; i < 15; i++)
	{
		str = get_next_line(a);
		printf("string number '%d': %s\n", i, str);
		free(str);
		str = get_next_line(b);
		printf("string number '%d': %s\n\n", i, str);
		free(str);
	}
	close(a);
	//free(str);
}*/
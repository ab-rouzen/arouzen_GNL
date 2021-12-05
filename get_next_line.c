/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:21:55 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/05 19:40:02 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_refill(char *buffer, char *temp, int i)
{
	char	*loc;
	char	*buff2;

	loc = ft_strchr(&temp[i], '\n');
	if (!buffer)
	{
		if (loc)
			buffer = malloc(loc - temp + 2);
		else
			buffer = malloc(BUFFER_SIZE + 2);
		return (buffer);
	}
	if (loc)
		buff2 = malloc(ft_strlen(buffer) + loc - temp + 2);
	else
		buff2 = malloc(ft_strlen(buffer) + BUFFER_SIZE + 2);
	ft_strcpy(buff2, buffer);
	free (buffer);
	return (buff2);

}

char	*get_next_line(int fd)
{
	static int	i = 0;
	int			j;
	int			c_eof;
	char		*buffer;
	static char	temp[BUFFER_SIZE + 1];

	buffer = NULL;
	j = 0;
	while (1)
	{
		if (!i)
		{
			c_eof = (read(fd, temp, BUFFER_SIZE));
			if (c_eof == -1)
				return (NULL);
			if (c_eof == 0)
			{
				if (temp[j] != '\n')
					return (buffer);
				return (NULL);
			}
			else
				temp[c_eof] = 0;
		}
		buffer = next_refill(buffer, temp, i);
		while (temp[i] != '\n' && temp[i])
			buffer[j++] = temp[i++];
		if (temp[i] == '\n' && temp[i])
		{
			buffer[j++] = '\n';
			buffer[j] = '\0';
			if (i == c_eof - 1)
				i = 0;
			else
				i++;
			return (buffer);
		}
		buffer[j] = '\0';
		i = 0;
	}
	return (NULL);
}
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*n_line;

	i = 0;
	fd = open("multi_ln", O_RDONLY);
	if (fd == -1)
		return (-1);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
	n_line = get_next_line(fd);
	ft_putstr_fd(n_line, 1);
	free(n_line);
return (0);
}
*/

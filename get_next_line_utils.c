/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:32:13 by arouzen           #+#    #+#             */
/*   Updated: 2022/12/05 23:19:38 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	destroy(char *temp, int param)
{
	int	i;

	i = 0;
	if (param)
		while (temp[i] != '\n' && i < BUFFER_SIZE)
			temp[i++] = 0x00;
	else
		while (i < BUFFER_SIZE)
			temp[i++] = 0x00;
	temp[i] = 0x00;
}

int	loc_nl(char *str, int param, int c_eof)
{
	int	loc;

	loc = 0;
	while (str[loc] == 0x00 && loc < c_eof)
		loc++;
	if (param == 1)
		return (loc);
	while (str[loc] != '\n' && loc[str] && loc < c_eof)
		loc++;
	if (str[loc] == '\n')
		return (loc + 1);
	return (loc);
}

char	*arm_line(int fd, char **holder, char *buffer)
{
	int		size_read;
	int		i;

	size_read = loc_nl(holder[fd], 0, BUFFER_SIZE);
	while (1)
	{
		i = loc_nl(holder[fd], 1, size_read);
		if (i == size_read)
		{
			i = 0;
			size_read = (read(fd, holder[fd], BUFFER_SIZE));
			if (!size_read || size_read == -1)
			{
				free(holder[fd]);
				holder[fd] = NULL;
				return (buffer);
			}
		}
		if (!allo_mem(&buffer, holder[fd], size_read))
			return (NULL);
		else if (copycat(holder[fd], buffer, size_read, &i) == COMPLETE)
			return (buffer);
		destroy(holder[fd], 1);
	}
	return (0);
}

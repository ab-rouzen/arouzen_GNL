/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:28:25 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/11 13:28:34 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*allo_mem(char **buffer, char *temp, int c_eof)
{
	int		blk_size;
	char	*buff2;

	blk_size = loc_nl(temp, 0, c_eof) - loc_nl(temp, 1, c_eof);
	buff2 = malloc(ft_strlen(*buffer) + blk_size + 2);
	if (!buff2)
		return (NULL);
	ft_strcpy(buff2, *buffer);
	free (*buffer);
	*buffer = buff2;
	return ("ok:)");
}

int	copycat(char *temp, char *buffer, int c_eof, int *temp_pos)
{
	int	j;
	int	i;

	i = loc_nl(temp, 1, c_eof);
	j = ft_strlen(buffer);
	while (temp[i] != '\n' && i < c_eof)
		buffer[j++] = temp[i++];
	if (temp[i] == '\n')
	{
		buffer[j] = '\n';
		buffer[j + 1] = '\0';
		*temp_pos += i - loc_nl(temp, 1, c_eof);
		destroy(temp, 1);
		return (COMPLETE);
	}
	buffer[j] = '\0';
	*temp_pos += i - loc_nl(temp, 1, c_eof);
	destroy(temp, 1);
	return (INCOMPLETE);
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

char	*get_next_line(int fd)
{
	static char	*holder[512 * 2];
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || fd > 512 * 2)
		return (NULL);
	if (!holder[fd])
	{
		holder[fd] = malloc(BUFFER_SIZE);
		destroy(holder[fd], 0);
	}
	return (arm_line(fd, holder, buffer));
}

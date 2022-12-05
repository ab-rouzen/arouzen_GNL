/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:21:55 by arouzen           #+#    #+#             */
/*   Updated: 2022/12/05 23:19:43 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	int		i;
	char	*nstr;

	nstr = (char *)str;
	if (!nstr)
		return (0);
	i = 0;
	while (nstr[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src [i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
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

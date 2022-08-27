/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:28:50 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/11 13:29:01 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

size_t	ft_strlen(const char *str)
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

char	*ft_strcpy(char *dst, const char *src)
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

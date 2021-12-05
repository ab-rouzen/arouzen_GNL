/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:32:13 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/04 15:55:10 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	int		i;
	char	*nstr;

	nstr = (char *)str;
	i = 0;
	while (nstr[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i++] = '\0';
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*us;
	char	nc;

	i = 0;
	us = (char *)s;
	nc = (char)c;
	while (us[i] != nc && us[i])
		i++;
	if (us[i] == nc)
		return (&us[i]);
	return (NULL);
}

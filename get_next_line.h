/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:32:40 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/11 13:29:59 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define COMPLETE 1
# define INCOMPLETE 0

void	destroy(char *temp, int param);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);

#endif

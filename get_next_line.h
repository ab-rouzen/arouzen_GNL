/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:32:40 by arouzen           #+#    #+#             */
/*   Updated: 2022/12/05 23:20:53 by arouzen          ###   ########.fr       */
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
int		loc_nl(char *str, int param, int c_eof);
char	*arm_line(int fd, char **holder, char *buffer);
int		copycat(char *temp, char *buffer, int c_eof, int *temp_pos);
char	*allo_mem(char **buffer, char *temp, int c_eof);

#endif

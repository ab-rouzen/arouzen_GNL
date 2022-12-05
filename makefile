# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:37:25 by arouzen           #+#    #+#              #
#    Updated: 2022/12/05 23:22:39 by arouzen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re bonus clean fclean $(NAME)

NAME = libgnl.a
INCL = get_next_line.h
INCL_B = get_next_line_bonus.h
BUILD_DIR = build/
MAND_SRCS = get_next_line.c \
			get_next_line_utils.c

MAND_OBJS = $(MAND_SRCS:%.c=$(BUILD_DIR)%.o)
BONU_SRCS = get_next_line_bonus.c \
			get_next_line_utils_bonus.c

BUFFER_SIZE = 1024
BONU_OBJS = $(BONU_SRCS:%.c=$(BUILD_DIR)%.o)
AR = ar
ARFLAGS = -rs
CC = gcc
LIB  = libgnl.a
FLAGS = -Wall -Wextra -Werror


all : $(NAME)
	@echo Everything is up to go!

$(NAME) : $(MAND_OBJS) $(INCL)
	@echo Checking files...
	$(AR) $(ARFLAGS) $(LIB) $(MAND_OBJS)

bonus : $(BONU_OBJS) $(INCL_B)
	@echo Compiling bonus + mandatory objects...
	$(AR) $(ARFLAGS) $(LIB) $(BONU_OBJS)

clean :
	@echo cleaning up...
	rm -rf $(BUILD_DIR)

$(BUILD_DIR)%.o : %.c $(INCL)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c  $< -o $@

fclean : clean
	rm -rf $(LIB)

re : fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/03 13:33:38 by vlevko            #+#    #+#              #
#    Updated: 2018/04/06 17:50:03 by vlevko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CHECK = checker.c

SRC_PS = push_swap.c \
	ps_do_sort.c \
	ps_let_sort.c \
	ps_merge_a.c \
	ps_merge_a_case.c \
	ps_sort.c \
	ps_try_a_more.c \
	ps_try_b_case.c \
	ps_try_do_sort.c \
	ps_try_sort.c \
	ps_utils.c

SRC_LIB = lib_check.c \
	lib_err.c \
	lib_list.c \
	lib_sort.c

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_LIB = $(SRC_LIB:.c=.o)

NAME_CHECK = checker

NAME_PS = push_swap

CFLAGS = -Wall -Wextra -Werror

LPATH = libft/

LFLAGS = -L libft/ -lft

CC = gcc

all: $(NAME_CHECK) $(NAME_PS)

$(NAME_CHECK): $(OBJ_CHECK) $(OBJ_LIB)
	@make -C $(LPATH)
	@$(CC) $(CFLAGS) -o $(NAME_CHECK) $(SRC_CHECK) $(SRC_LIB) $(LFLAGS)

$(NAME_PS): $(OBJ_PS) $(OBJ_LIB)
	@$(CC) $(CFLAGS) -o $(NAME_PS) $(SRC_PS) $(SRC_LIB) $(LFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ_CHECK) $(OBJ_PS) $(OBJ_LIB)
	@make clean -C $(LPATH)

fclean: clean
	@/bin/rm -f $(NAME_CHECK) $(NAME_PS)
	@make fclean -C $(LPATH)

re: fclean all

.PHONY: all clean fclean re

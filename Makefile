# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:52:41 by tsantana          #+#    #+#              #
#    Updated: 2024/05/10 14:41:33 by tsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror -g3

HEADERS	:= -I includes/ -I libs/libft/

LIBFT	:= libs/libft/libft.a

SRC		:= src/push_swap.c \
		   src/ps_validation.c \
		   src/ps_s_moves.c \
		   src/ps_rr_moves.c \
		   src/ps_r_moves.c \
		   src/ps_p_moves.c \
		   src/ps_error.c \
		   src/list_work.c \
		   src/ft_atol.c \
		   src/ps_utils.c \
		   src/ps_utils_2.c \
		   src/ps_utils_3.c \
		   src/test.c \
		   src/moves.c \
		   src/parse5.c

OBJ		:= $(SRC:%.c=%.o)

%.o: &.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER) && printf "Compiling: $(notdir $<)"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -Llibs/libft -lft

$(LIBFT):
	@make -C libs/libft/ --no-print-directory

clean:
	rm -rf $(OBJ)
	make -C libs/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libs/libft fclean

re:	clean all

PHONY: all, clean, fclean, re

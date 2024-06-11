# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labderra <labderra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 09:26:13 by labderra          #+#    #+#              #
#    Updated: 2024/06/11 09:16:01 by labderra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ../libft/libft.a
FT_PRINTF = ../ft_printf/libftprintf.a
SRC = main.c \
	initialize.c \
	moves_1.c \
	moves_2.c \
	moves_3.c \
	costs.c \
	sorting.c \
	checks.c 
	
CC = clang -Wall -Wextra -Werror -gdwarf-4
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@ 

$(LIBFT) : 
	make -C "../libft"
	make -C "../libft" bonus

$(FT_PRINTF) :
	make -C "../ft_printf"

%.o : %.c
	$(CC) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

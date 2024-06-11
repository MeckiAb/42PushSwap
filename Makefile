# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labderra <labderra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 09:26:13 by labderra          #+#    #+#              #
#    Updated: 2024/06/11 14:08:35 by labderra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
SRC = main.c \
	initialize.c \
	moves_1.c \
	moves_2.c \
	moves_3.c \
	costs.c \
	sorting.c \
	checks.c 
SRC_BONUS = main_bonus.c \
	initialize_bonus.c\
	moves_1_bonus.c \
	moves_2_bonus.c \
	moves_3_bonus.c \
	checks_bonus.c
	
CC = clang -Wall -Wextra -Werror -gdwarf-4
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@ 

$(LIBFT) : 
	make -C "libft"
	make -C "libft" bonus

$(FT_PRINTF) :
	make -C "ft_printf"

%.o : %.c
	$(CC) -c $< -o $@

clean : 
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make -C "libft" clean
	make -C "ft_printf" clean

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -C "libft" fclean
	make -C "ft_printf" fclean

re : fclean all

bonus: $(BONUS)

$(BONUS) : $(OBJ_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(FT_PRINTF) -o $@ 

.PHONY : all clean fclean re bonus

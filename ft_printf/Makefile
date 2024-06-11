NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
AR = ar -csr

SRC = ft_printf.c \
print_char.c \
print_str.c \
print_nbr.c \
print_unbr.c \
print_hex.c \
print_ptr.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $?

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	cc $(NAME) main.c
	./a.out

.PHONY : all clean fclean re
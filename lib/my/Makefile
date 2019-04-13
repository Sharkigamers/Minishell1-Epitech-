##
## EPITECH PROJECT, 2018
## Makefile_lib
## File description:
## Makefile wich will compile the lib
##

SRC	=	printf/lib/my_putchar.c	\
		printf/lib/my_putstr.c	\
		printf/lib/my_put_nbr.c	\
		printf/lib/my_binary.c	\
		printf/lib/my_octal.c	\
		printf/lib/my_hexa.c	\
		printf/lib/my_sup_hexa.c	\
		printf/lib/my_strlen.c	\
		printf/lib/my_strcpy.c	\
		printf/lib/my_revstr.c	\
		printf/lib/unsigned_putnbr.c	\
		printf/lib/my_put_long_nbr.c	\
		printf/lib/my_put_longlong_nbr.c	\
		printf/lib/my_put_short_nbr.c	\
		printf/lib/my_put_char_nbr.c	\
		printf/lib/my_long_hexa.c	\
		printf/src/basic_flags.c	\
		printf/src/my_printf.c	\
		printf/src/length_modifier.c	\
		printf/src/non_printable_flag.c	\
		printf/src/basic_hashtag_flags.c	\
		my_strcmp.c	\
		my_strdup.c	\
		my_strcat.c	\
		atoi.c	\
		my_putstrerror.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I ./printf/include/

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f libmy.a

re:	fclean all

.PHONY: all clean fclean re

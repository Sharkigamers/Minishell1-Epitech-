##
## EPITECH PROJECT, 2018
## matchstick
## File description:
## Makefile
##

SRC	=	src/f_minishell.c	\
		src/annex_minishell.c	\
		src/env.c	\
		src/set_env.c	\
		src/unset_env.c	\
		src/annex_unset_env.c	\
		src/fill_argv.c	\
		src/exec.c	\
		src/annex_exec.c	\
		src/cd.c	\
		src/annex_cd.c	\
		src/main.c	\
		src/exit.c	\
		src/error_seg.c	\
		src/main_loop.c	\
		src/init_oldpwd.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) $(LIB) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY: all clean fclean re

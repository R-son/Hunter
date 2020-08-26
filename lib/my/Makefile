##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compiles My_Hunter's lib
##

SRC	= 	my_putchar.c	\
		my_strlen.c	\
		my_putstr.c

NAME	= 	libmy.a

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)
	rm -rf *~
	rm -rf *#
	rm -rf include/*~

re: fclean all

.PHONY: all clean fclean re
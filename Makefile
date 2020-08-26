##
## EPITECH PROJECT, 2018
## my_runner's Makefile
## File description:
## my_runner
##

SRC     =       main.c	\
				title_screen.c	\
				launch_game.c\
				target_set.c	\
				game_over.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_hunter

CFLAGS  =       -I include

LIB     =       lib/my/libmy.a

GCC     =       gcc -o $(NAME)

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C ./lib/my/
	$(GCC) -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio $(SRC) -L. $(LIB)

clean:
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f ./lib/my/*.o
	rm -f ./lib/my/*.c~
	rm -f ./lib/my/*#
	rm -f ./lib/my/Makefile~
	rm -f ./include/*.h~
	rm -f my_hunter

fclean: clean
	rm -f $(NAME)
	rm ./lib/my/libmy.a

re:    fclean all

.PHONY: fclean clean re all

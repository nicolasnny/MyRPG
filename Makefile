##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my first make file
##

CC = gcc

MAIN	=

SRC     =	src/main.c	\
		src/my_rpg.c	\
		src/init/init_game.c	\
		src/init/init_map.c	\
		src/events.c	\
		src/clean.c	\
		src/display.c	\
		src/err_handling.c	\
		src/time.c	\
		src/moves/player.c	\
		src/assist_func/my_str_to_word_class_array.c	\
		src/assist_func/file.c	\

CRFLAGS	=	--coverage -lcriterion

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LDFLAGS =

LDLIBS	=	$(CSFML)

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

LIBNAME	=	libmy.a

TEST_SRC	=	tests/unit_tests.c

TNAME	=	unit_tests

all:	$(NAME)

lib:
	$(MAKE) -C lib/my

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(MAIN) $(OBJ) $(LDLIBS)

tests_run: lib
	$(CC) $(LDFLAGS) -o $(TNAME) $(TEST_SRC) $(OBJ) $(CRFLAGS) $(LDLIBS)
	./$(TNAME)

clean:
	$(RM) -f $(OBJ) *~  *.gcda *.gcno src/*.gc*

fclean:	clean
	$(RM) -f $(NAME) $(TNAME)

debug:	CPPFLAGS += -g3
debug:	re

re:     fclean all

.PHONY: all lib tests_run clean fclean re debug

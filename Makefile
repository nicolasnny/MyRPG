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
			src/init/init_entity.c	\
			src/events.c	\
			src/clean.c	\
			src/display.c	\
			src/err_handling.c	\
			src/time.c	\
			src/moves/player.c	\
			src/moves/npc.c	\
			src/assist_func/my_str_to_word_class_array.c	\
			src/assist_func/file.c	\
			src/assist_func/random.c	\
			src/assist_func/my_strstrlen.c	\
			src/linked_list/linked_list.c	\
			src/linked_list/revert_list.c	\
			src/ecs/system.c	\
			src/ecs/get_entities.c	\
			src/ecs/set_entities.c	\
			src/animate/make_life.c	\
			src/collisions/check_collisions.c	\
			src/user_interface/start_menu/main_page.c	\
			src/user_interface/hovering.c				\

UT_SRC	=	tests/unit_tests.c	\
			tests/test.c	\
			src/my_rpg.c	\
			src/init/init_game.c	\
			src/init/init_map.c	\
			src/init/init_entity.c	\
			src/events.c	\
			src/clean.c	\
			src/display.c	\
			src/err_handling.c	\
			src/time.c	\
			src/moves/player.c	\
			src/moves/npc.c	\
			src/assist_func/my_str_to_word_class_array.c	\
			src/assist_func/file.c	\
			src/assist_func/random.c	\
			src/assist_func/my_strstrlen.c	\
			src/linked_list/linked_list.c	\
			src/linked_list/revert_list.c	\
			src/ecs/system.c	\
			src/ecs/get_entities.c	\
			src/ecs/set_entities.c	\
			src/animate/make_life.c	\
			src/collisions/check_collisions.c	\
			src/ecs/destroy_entity.c	\
			src/user_interface/start_menu/main_page.c	\
			src/user_interface/hovering.c				\

CRFLAGS	=	--coverage -lcriterion

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LDFLAGS =

LDLIBS	=	$(CSFML)

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

LIBNAME	=	libmy.a

TNAME	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(MAIN) $(OBJ) $(LDLIBS)

tests_run:
	$(CC) -I include/ -o $(TNAME) $(UT_SRC) $(CRFLAGS) $(LDLIBS)
	./$(TNAME)

clean:
	$(RM) -f $(OBJ) *~  *.gcda *.gcno src/*.gc*

fclean:	clean
	$(RM) -f $(NAME) $(TNAME)

debug:	CPPFLAGS += -g3
debug:	re

asan:	CC	=	clang -fsanitize=address
asan:	CFLAGS += -g3
asan:	re

re:     fclean all

.PHONY: all lib tests_run clean fclean re debug asan

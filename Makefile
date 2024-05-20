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
				src/moves/get_new_pos.c	\
				src/assist_func/my_str_to_word_class_array.c	\
				src/assist_func/file.c	\
				src/assist_func/random.c	\
				src/assist_func/my_strstrlen.c	\
				src/linked_list/linked_list.c	\
				src/linked_list/revert_list.c	\
				src/ecs/system.c	\
				src/ecs/get_entities.c	\
				src/ecs/set_entities.c	\
				src/ecs/unset_entity.c	\
				src/animate/make_life.c	\
				src/collisions/check_collisions.c	\
				src/user_interface/start_menu/main_page.c	\
				src/user_interface/start_menu/settings.c	\
				src/user_interface/hovering.c				\
				src/game_state.c							\
				src/rectangle.c								\
				src/sprite.c								\
				src/config_parser/get_conf_infos.c			\
				src/config_parser/param_funcs.c				\
				src/init/set_name.c							\
				src/config_parser/parse_dir.c				\
				src/init/init_inventory.c	\
				src/inventory/inventory.c	\
				src/user_interface/in_game_menu/in_game_menu.c	\
				src/view.c						\
				src/inventory/set_inventory.c	\
				src/inventory/manage.c	\
				src/bind_assigning/bind_events.c	\
				src/fight/range.c	\
				src/fight/kill.c	\

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
			src/moves/get_new_pos.c	\
			src/assist_func/my_str_to_word_class_array.c	\
			src/assist_func/file.c	\
			src/assist_func/random.c	\
			src/assist_func/my_strstrlen.c	\
			src/linked_list/linked_list.c	\
			src/linked_list/revert_list.c	\
			src/ecs/system.c	\
			src/ecs/get_entities.c	\
			src/ecs/set_entities.c	\
			src/ecs/unset_entity.c	\
			src/animate/make_life.c	\
			src/collisions/check_collisions.c	\
			src/ecs/destroy_entity.c	\
			src/user_interface/start_menu/main_page.c	\
			src/user_interface/hovering.c				\
			src/init/init_inventory.c	\
			src/inventory/inventory.c	\
			src/inventory/set_inventory.c	\
			src/inventory/manage.c	\
			src/fight/range.c	\
			src/fight/kill.c	\

CRFLAGS	=	--coverage -lcriterion

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LDFLAGS =	-L./lib/

LDLIBS	=	-lmy $(CSFML) -lm

LIBNAME	=	libmy.a

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

LIBNAME	=	libmy.a

TNAME	=	unit_tests

all:	libb $(NAME)

libb:
	$(MAKE) all -C lib/
all:	libb $(NAME)

libb:
	$(MAKE) all -C lib/

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(MAIN) $(OBJ) $(LDFLAGS) $(LDLIBS)
	$(CC) $(LDFLAGS) -o $(NAME) $(MAIN) $(OBJ) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(CC) -I include/ -o $(TNAME) $(UT_SRC) $(CRFLAGS) $(LDLIBS)
	./$(TNAME)

clean:
	$(MAKE) clean -C lib/
	$(MAKE) clean -C lib/
	$(RM) -f $(OBJ) *~  *.gcda *.gcno src/*.gc*

fclean:	clean
	$(MAKE) fclean -C lib/
	$(MAKE) fclean -C lib/
	$(RM) -f $(NAME) $(TNAME)

debug:	CPPFLAGS += -g3
debug:	re

asan:	CC	=	clang -fsanitize=address
asan:	CFLAGS += -g3
asan:	re

re:     fclean all

.PHONY: all lib tests_run clean fclean re debug asan

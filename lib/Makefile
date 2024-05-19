##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Write a Makefile that compiles your libmy.
## It should perform the following actions:
##

CC	=	gcc

SRC	=	my_print_str_array.c		\
		my_strdup_ban_char.c		\
		my_free_str_array.c			\
		my_strcat.c					\
		my_strstrlen.c				\
		my_str_array_dup_ban_str.c	\
		my_str_to_word_array.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

HFILE	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

copy:
	cp libmy.a  ../libmy.a
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

debug:	CPPFLAGS += -g3
debug:	re

re:	fclean all

.PHONY: all copy clean fclean debug re

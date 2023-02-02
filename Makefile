##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC	=	main.c \
		particle.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	particle_manager

INCLUDE	=	-I./include
CFLAGS	=	-Wall -Wextra -g3

LDFLAGS	=	-lcsfml-graphics -lcsfml-system

BOLD	=	\e[1m
GREEN	=	\e[92m
WHITE	=	\e[0m

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LDFLAGS)
	@echo -e "$(BOLD)$(TITLE)$(GREEN)COMPILATION COMPLETE\n$(WHITE)"

valgrind:
	@make -C lib
	gcc src/*.c -g3

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	make fclean -C lib
	rm -f $(NAME)

allclean: fclean
	rm -f $(USE)

re:	fclean	all

test_build:
	gcc $(TEST) -o unit_test --coverage -lcriterion -Wall

test_clean:
	rm -f *.gcno
	rm -f *.o
	rm -f *.gcda
	rm unit_test

test_run: test_build
	./unit_test
	make test_clean

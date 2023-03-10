##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my files
##

NAME	=	particle_manager

SRC	=	src/main.c \
		src/destroy_anims.c \
		src/test_anims.c \
		src/event_manager.c \
		src/update_manager.c \
		src/draw_manager.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./include -fsanitize=address
CFLAGS	=	-Wall -Wextra -g3

LIB		=	-L./lib/ -lparticle

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lm

BOLD	=	\e[1m
GREEN	=	\e[92m
WHITE	=	\e[0m

all:	$(OBJ)
		@cd lib/particle && $(MAKE)
		@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LIB) $(LDFLAGS)
		@echo -e "$(BOLD)$(TITLE)$(GREEN)COMPILATION COMPLETE\n$(WHITE)"

clean:
		@cd lib/particle && $(MAKE) clean
		@rm -f $(OBJ)

fclean:	clean
		@cd lib/particle && $(MAKE) fclean
		@rm -f $(NAME)

lib_re:
		@cd lib/particle && $(MAKE) re

re:	fclean lib_re all

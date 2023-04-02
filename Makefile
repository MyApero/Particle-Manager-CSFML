##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my files
##

NAME	=	particle_manager

SRC	=	src/main.c \
		src/destroy_anims.c \
		src/anims/first_anim.c \
		src/anims/second_anim.c \
		src/anims/third_anim.c \
		src/event_manager.c \
		src/update_manager.c \
		src/draw_manager.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -g3 -fsanitize=address

LIB		=	-L./lib/ -lparticle

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lm

BOLD	=	\e[1m
GREEN	=	\e[92m
WHITE	=	\e[0m

all:	$(NAME)

$(NAME):	$(OBJ)
		@cd lib/particle && $(MAKE)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)  $(LIB) $(LDFLAGS)
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

##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my lib
##

SRC	=	set/set_shape_end.c \
		set/set_shape_start.c \
		set/set_shape.c \
		anim_create.c \

OBJ	=	$(SRC:.c=.o)

INCLUDE	= -I./
NAME	=	libparticle.a
HEADER	=	particle.h
CFLAGS	=	-g3 -c
LDFLAGS	=	-lcsfml-graphics -lcsfml-system

all:	$(NAME)

$(OBJ):	%.o: %.c
	gcc $(CFLAGS) -o $@ $(INCLUDE) $< $(LDFLAGS)
	echo -e "$(BOLD)$(BLUE)File $(RED)$@$(BLUE) created.$(WHITE)"

$(NAME):	$(OBJ)
		mkdir -p ../../include
		cp particle.h ../../include/
		cp struct_particle.h ../../include/
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my lib
##

SRC	=	set/anim_set_color.c \
		set/anim_set_duration.c \
		set/anim_set_frequency.c \
		set/anim_set_rotation.c \
		set/anim_set_scale_limit.c \
		set/anim_set_scale_modifier.c \
		set/anim_set_scale.c \
		set/anim_set_shape_start.c \
		set/anim_set_shape.c \
		set/anim_set_shape_end.c \
		set/anim_set_speed.c \
		set/anim_set_is_generating.c \
		create/anim_create.c \
		create/particle_create.c \
		create/create_particle_form.c \
		get_delta_time.c \
		particle_update.c \
		anim_update.c \
		anim_display.c \
		anim_free.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	= -I./
NAME	=	libparticle.a
HEADER	=	particle.h
CFLAGS	=	-g3 -c
LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lm

BOLD	=	\e[1m
GREEN	=	\e[92m
WHITE	=	\e[0m
BLUE	=	\e[94m
RED		=	\e[31m

all:	$(NAME)

$(OBJ):	%.o: %.c
	@gcc $(CFLAGS) -o $@ $(INCLUDE) $< $(LDFLAGS)
	@echo -e "$(BOLD)$(BLUE)File $(RED)$@$(BLUE) created.$(WHITE)"

$(NAME):	$(OBJ)
		@mkdir -p ../../include
		@cp particle.h ../../include/
		@cp struct_particle.h ../../include/
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../
		@echo -e "$(BOLD)$(GREEN) -- LIB SUCCESSFULLY COMPILED -- $(WHITE)"

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)
		@rm -f ../$(NAME)

re:	fclean all

##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my lib
##

SRC	=	set/anim_set_id.c \
		set/anim_set_color.c \
		set/anim_set_duration.c \
		set/anim_set_frequency.c \
		set/anim_set_batch_size.c \
		set/anim_set_rotation.c \
		set/anim_set_scale_modifier.c \
		set/anim_set_scale.c \
		set/anim_set_shape_part.c \
		set/anim_set_shape_start.c \
		set/anim_set_shape_end.c \
		set/anim_set_speed.c \
		set/anim_set_is_generating.c \
		create/anim_create.c \
		create/anim_append.c \
		create/particle_create/particle_create.c \
		create/particle_create/get_from_circle.c \
		create/particle_create/get_from_rect.c \
		create/particle_create/get_random_pos.c \
		create/particle_create/set_particle_shape.c \
		utils/v2f_operations.c \
		utils/vector_norm.c \
		utils/get_random_between.c \
		utils/get_delta_time.c \
		update/anim_update.c \
		update/particle_update/particle_update.c \
		update/particle_update/particle_move_or_ended.c \
		update/particle_update/particle_rotate.c \
		anim_draw.c \
		destroy/destroy_shape.c \
		destroy/anim_destroy.c \
		utils/is_anim_ended.c \
		particle_destroy.c

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

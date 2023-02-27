/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>

static sfRectangleShape *create_default_shape(sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}

anim_t *anim_create(void)
{
    anim_t *anim = malloc(sizeof(anim_t));
    anim->particles = NULL;
    anim->color_start = ANIM_COLOR;
    anim->color_end = anim->color_start;
    anim->particle_shape_type = RECT;
    anim->particle_shape.rect = create_default_shape(anim->color_start);
    anim->shape_start_type = RECT;
    anim->shape_start.rect = create_default_shape(anim->color_start);
    anim->shape_end_type = RECT;
    anim->shape_end.rect = create_default_shape(anim->color_start);
    anim->speed = ANIM_SPEED;
    anim_set_frequency(anim, ANIM_FREQUENCY);
    anim->duration = ANIM_DURATION;
    anim->time_elapsed = 0;
    anim->scale = ANIM_SCALE;
    anim->scale_modifier = ANIM_SCALE;
    anim->scale_limit = ANIM_SCALE;
    anim->rotation = 0;
    anim->is_generating = TRUE;
    return anim;
}

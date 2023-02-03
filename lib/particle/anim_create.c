/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>

sfRectangleShape *create_default_shape(sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, color);
}

anim_t *anim_create(void)
{
    anim_t *anim = malloc(sizeof(anim_t));
    anim->particles = NULL;
    anim->start_color = sfColor_fromRGBA(255, 0, 0, 150);
    anim->end_color = anim->start_color;
    anim->particle_shape_type = RECT;
    anim->particle_shape.rect = create_default_shape(anim->start_color);
}

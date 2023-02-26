/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape_start
*/

#include "particle.h"

void anim_set_shape_start(anim_t *anim, shape_type_t shape_type, void *shape)
{
    anim->shape_start_type = shape_type;
    if (shape_type == POINT)
        anim->shape_start.point = shape;
    if (shape_type == RECT)
        anim->shape_start.rect = shape;
    if (shape_type == CIRCLE)
        anim->shape_start.circle = shape;
}

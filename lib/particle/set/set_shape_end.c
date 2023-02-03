/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape_ends
*/

#include "particle.h"

void anim_set_shape_end(anim_t *anim, shape_type_t shape_type, void *shape)
{
    anim->shape_end_type = shape_type;
    if (shape_type == POINT)
        anim->shape_end.point = shape;
    if (shape_type == RECT)
        anim->shape_end.rect = shape;
    if (shape_type == CIRCLE)
        anim->shape_end.circle = shape;
}

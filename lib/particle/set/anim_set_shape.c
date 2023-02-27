/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape
*/

#include "particle.h"

void anim_set_shape(anim_t *anim, shape_type_t shape_type, void *shape)
{
    anim->particle_shape_type = shape_type;
    if (shape_type == RECT)
        anim->particle_shape.rect = shape;
    if (shape_type == CIRCLE)
        anim->particle_shape.circle = shape;
}

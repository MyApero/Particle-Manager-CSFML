/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape
*/

#include "particle.h"

void anim_set_particle_shape(anim_t *anim, shape_type_t shape_type, void *shape)
{
    if (anim->particle_shape_default) {
        destroy_shape(anim->particle_shape_type, anim->particle_shape);
        anim->particle_shape_default = sfFalse;
    }
    anim->particle_shape_type = shape_type;
    switch (shape_type) {
        case 0 ... 1: anim->particle_shape.rect = shape; break;
        case 2 ... 3: anim->particle_shape.circle = shape; break;
    };
}

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
    switch (shape_type) {
        case 0 ... 1: anim->shape_start.rect = shape; break;
        case 2 ... 3: anim->shape_start.circle = shape; break;
    };
}

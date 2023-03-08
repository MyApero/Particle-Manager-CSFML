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
    switch (shape_type) {
        case 0 ... 1: anim->shape_end.rect = shape; break;
        case 2 ... 3: anim->shape_end.circle = shape; break;
    };
}

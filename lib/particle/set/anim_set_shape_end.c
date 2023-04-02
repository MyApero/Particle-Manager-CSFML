/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape_ends
*/

#include "particle.h"

void anim_set_shape_end(anim_t *anim, shape_type_t shape_type, void *shape)
{
    if (anim->shape_end_default) {
        destroy_shape(anim->shape_end_type, anim->shape_end);
        anim->shape_end_default = sfFalse;
    }
    anim->shape_end_type = shape_type;
    switch (shape_type) {
        case RECT_OUTLINE: case RECT:
            anim->shape_end.rect = shape; break;
        case CIRCLE_OUTLINE: case CIRCLE:
            anim->shape_end.circle = shape; break;
        default: break;
    };
}

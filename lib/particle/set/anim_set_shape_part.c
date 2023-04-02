/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape
*/

#include "particle.h"

void anim_set_shape_part(anim_t *anim, shape_type_t shape_type, void *shape)
{
    if (anim->shape_part_default) {
        destroy_shape(anim->shape_part_type, anim->shape_part);
        anim->shape_part_default = sfFalse;
    }
    anim->shape_part_type = shape_type;
    switch (shape_type) {
        case RECT_OUTLINE: case RECT:
            anim->shape_part.rect = shape;
            break;
        case CIRCLE_OUTLINE: case CIRCLE:
            anim->shape_part.circle = shape;
            break;
        case SPRITE:
            anim->shape_part.sprite = shape;
            break;
        default:
            break;
    };
}

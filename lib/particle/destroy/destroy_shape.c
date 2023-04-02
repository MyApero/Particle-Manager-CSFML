/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** destroy_shape
*/

#include "particle.h"

void destroy_shape(shape_type_t shape_type, shape_t shape)
{
    switch (shape_type) {
    case RECT_OUTLINE:
    case RECT:
        sfRectangleShape_destroy(shape.rect);
        break;
    case CIRCLE_OUTLINE:
    case CIRCLE:
        sfCircleShape_destroy(shape.circle);
        break;
    case SPRITE:
        sfSprite_destroy(shape.sprite);
        break;
    default:
        break;
    }
}

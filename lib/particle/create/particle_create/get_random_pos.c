/*
** EPITECH PROJECT, 2023
** lib/particle/create/get_random_pos
** File description:
** get a random particle pos
*/

#include "particle.h"
#include <stdlib.h>

v2f get_random_pos(shape_t shape, shape_type_t shape_type)
{
    switch (shape_type) {
    case RECT:
        return get_from_rect(sfRectangleShape_getGlobalBounds(shape.rect));
    case RECT_OUTLINE:
        return sfRectangleShape_getPoint(shape.rect,
            rand() % sfRectangleShape_getPointCount(shape.rect));
    case CIRCLE:
        return get_from_circle(shape.circle);
    case CIRCLE_OUTLINE:
        return get_pos_from_circle_outline(shape.circle);
    case SPRITE:
        return get_from_rect(sfSprite_getGlobalBounds(shape.sprite));
    default:
        break;
    };
}

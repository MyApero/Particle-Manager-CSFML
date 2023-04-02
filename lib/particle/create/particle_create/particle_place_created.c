/*
** EPITECH PROJECT, 2023
** lib/particle/create/create_particle_form
** File description:
** create the particle at a certain place
*/

#include "particle.h"
#include <stdlib.h>

v2f particle_place_created(shape_t shape, shape_type_t shape_type)
{
    v2f vect;

    switch (shape_type) {
        case RECT: vect = created_from_rect(shape.rect); break;
        case RECT_OUTLINE: vect = sfRectangleShape_getPoint(shape.rect,
            rand() % (sfRectangleShape_getPointCount(shape.rect) - 1));
                break;
        case CIRCLE: vect = created_from_circle(shape.circle); break;
        case CIRCLE_OUTLINE: vect = sfCircleShape_getPoint(shape.circle,
            rand() % (sfCircleShape_getPointCount(shape.circle) - 1));
                break;
        default:
            break;
    };
    return vect;
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** destroy_shape
*/

#include "particle.h"

void destroy_shape(shape_type_t shape_type, shape_t shape)
{

    if (shape_type == RECT || shape_type == RECT_OUTLINE)
        sfRectangleShape_destroy(shape.rect);
    else if (shape_type == CIRCLE || shape_type == CIRCLE_OUTLINE)
        sfCircleShape_destroy(shape.circle);
}

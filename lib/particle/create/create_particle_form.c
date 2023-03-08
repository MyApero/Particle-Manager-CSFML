/*
** EPITECH PROJECT, 2023
** lib/particle/create/create_particle_form
** File description:
** create the particle at a certain place
*/

#include "particle.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>

static v2f created_from_rect(sfRectangleShape *rect)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect);
    v2f new_pos;

    printf("Size = %f, %f, %f, %f\n", bounds.left, bounds.top, bounds.height, bounds.width);
    if (abs((int) bounds.width) > 1e-5)
        new_pos.x = rand() % ((int) bounds.width) + bounds.left;
    else
        new_pos.x = bounds.left;
    if (abs((int) bounds.height) > 1e-5)
        new_pos.y = rand() % ((int) bounds.height) + bounds.top;
    else
        new_pos.y = bounds.top;
    printf("%f, %f\n", new_pos.x, new_pos.y);
    return new_pos;
}

static v2f created_from_circle(sfCircleShape *circle)
{
    v2f p1 = sfCircleShape_getPoint(circle,
        rand() % (sfCircleShape_getPointCount(circle) - 1));
    v2f p2 = sfCircleShape_getPoint(circle,
        rand() % (sfCircleShape_getPointCount(circle) - 1));
    v2f new_point;

    if (p1.x < p2.x)
        new_point.x = rand() % (int) (p1.x - p2.x) + p1.x;
    else if (p2.x < p1.x)
        new_point.x = rand() % (int) (p2.x - p1.x) + p2.x;
    else
        new_point.x = p1.x;
    if (p1.y < p2.y)
        new_point.y = rand() % (int) (p1.y - p2.y) + p1.y;
    else if (p2.y < p1.y)
        new_point.y = rand() % (int) (p2.y - p1.y) + p2.y;
    else
        new_point.y = p1.y;
    return new_point;
}

v2f particle_place_created(shape_t shape, shape_type_t shape_type)
{
    v2f vect;

    switch (shape_type) {
        case 0: vect = created_from_rect(shape.rect); break;
        case 1: vect = sfRectangleShape_getPoint(shape.rect, rand() %
                (sfRectangleShape_getPointCount(shape.rect) - 1));
                break;
        case 2: vect = created_from_circle(shape.circle); break;
        case 3: vect = sfCircleShape_getPoint(shape.circle, rand() %
                (sfCircleShape_getPointCount(shape.circle) - 1));
                break;
    };
    return vect;
}

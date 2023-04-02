/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_from_circle
*/

#include "particle.h"
#include <SFML/Graphics/CircleShape.h>
#include <stdlib.h>

static v2f get_new_point(v2f p1, v2f p2)
{
    v2f new_point;

    if (p1.x < p2.x) {
        new_point.x = rand() % (int)(p1.x - p2.x) + p1.x;
    } else if (p2.x < p1.x) {
        new_point.x = rand() % (int)(p2.x - p1.x) + p2.x;
    } else {
        new_point.x = p1.x;
    }
    if (p1.y < p2.y) {
        new_point.y = rand() % (int)(p1.y - p2.y) + p1.y;
    } else if (p2.y < p1.y) {
        new_point.y = rand() % (int)(p2.y - p1.y) + p2.y;
    } else {
        new_point.y = p1.y;
    }
    return new_point;
}

v2f created_from_circle(sfCircleShape *circle)
{
    v2f circle_pos = sfCircleShape_getPosition(circle);
    v2f p1 = sfCircleShape_getPoint(circle,
        rand() % (sfCircleShape_getPointCount(circle) - 20));
    v2f p2 = sfCircleShape_getPoint(circle,
        rand() % (sfCircleShape_getPointCount(circle) - 20));

    p1.x += circle_pos.x;
    p1.y += circle_pos.y;
    p2.x += circle_pos.x;
    p2.y += circle_pos.y;
    return get_new_point(p1, p2);
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_from_circle
*/

#include "particle.h"
#include <math.h>
#include <stdlib.h>

v2f get_pos_from_circle_outline(sfCircleShape *circle)
{
    v2f circle_pos = sfCircleShape_getPosition(circle);
    v2f point = sfCircleShape_getPoint(circle,
            rand() % (sfCircleShape_getPointCount(circle)));

    point.x += circle_pos.x;
    point.y += circle_pos.y;
    return point;
}

v2f get_pos_from_circle(sfCircleShape *circle)
{
    sfVector2f random_point;
    v2f center = sfCircleShape_getPosition(circle);
    float radius = sfCircleShape_getRadius(circle);
    float angle = ((float)rand() / RAND_MAX) * 2 * M_PI;
    float r = ((float)rand() / RAND_MAX) * radius;
    sfVector2f random_polar = {r * cosf(angle), r * sinf(angle)};

    center.x += radius;
    center.y += radius;
    random_point = (v2f){center.x + random_polar.x, center.y + random_polar.y};
    return random_point;
}

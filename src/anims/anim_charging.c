/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_charging
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>

static sfCircleShape *create_shape_start(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f){550, 150});
    sfCircleShape_setRadius(circle, 50);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 0));
    return circle;
}

static sfCircleShape *create_shape_end1(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f){550, 150});
    sfCircleShape_setRadius(circle, 50);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 0));
    return circle;
}

static sfCircleShape *create_shape_end2(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f){750, 350});
    sfCircleShape_setRadius(circle, 5);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 0));
    return circle;
}

static sfCircleShape *create_shape_part(void)
{
    sfCircleShape *circle = sfCircleShape_create();
    float radius = 3;

    sfCircleShape_setFillColor(circle, sfColor_fromRGB(200, 230, 210));
    sfCircleShape_setRadius(circle, radius);
    return circle;
}

anim_t *create_anim_charging(void)
{
    anim_t *anim = anim_create();

    anim_set_id(anim, CHARGING);
    anim_set_frequency(anim, 10);
    anim_set_batch_size(anim, 100);
    anim_set_duration(anim, 5);
    anim_set_speed(anim, 250);
    anim_set_scale(anim, (v2f){1, 2});
    anim_set_color(anim, sfColor_fromRGBA(230, 100, 100, 10), sfColor_fromRGB(
        0, 0, 0));
    anim_set_shape_start(anim, CIRCLE_OUTLINE, create_shape_start());
    anim_set_shape_end(anim, CIRCLE, create_shape_end2());
    anim_set_shape_part(anim, CIRCLE, create_shape_part());
    return anim;
}

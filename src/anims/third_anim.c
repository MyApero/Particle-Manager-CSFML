/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** third_anims
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>

static sfRectangleShape *create_shape_start(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f){400, 200});
    sfRectangleShape_setSize(rect, (v2f){20, 20});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 2));
    return rect;
}

static sfCircleShape *create_shape_end(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f){150, 150});
    sfCircleShape_setRadius(circle, 70);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 2));
    return circle;
}

static sfCircleShape *create_particle_shape(void)
{
    sfCircleShape *circle = sfCircleShape_create();
    float radius = 5;

    sfCircleShape_setFillColor(circle, sfColor_fromRGB(200, 230, 210));
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOrigin(circle, (v2f){radius / 2, radius / 2});
    return circle;
}

anim_t *create_third_anim(void)
{
    anim_t *anim = anim_create();

    anim_set_id(anim, BUG_CIRCLE);
    anim_set_frequency(anim, 300);
    anim_set_duration(anim, 0.2);
    anim_set_speed(anim, 250);
    anim_set_scale(anim, (v2f){1, 1});
    anim_set_color(anim, sfColor_fromRGBA(200, 230, 210, 200), sfColor_fromRGB(
        0, 0, 0));
    anim_set_shape_start(anim, RECT, create_shape_start());
    anim_set_shape_end(anim, CIRCLE, create_shape_end());
    anim_set_particle_shape(anim, CIRCLE, create_particle_shape());
    return anim;
}

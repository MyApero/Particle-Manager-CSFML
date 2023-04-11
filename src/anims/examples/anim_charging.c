/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_charging
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static shape_t *create_shape_start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f_t){550, 150});
    sfCircleShape_setRadius(circle, 50);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 0));
    shape->type = CIRCLE_OUTLINE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *create_shape_end(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f_t){750, 350});
    sfCircleShape_setRadius(circle, 5);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 0));
    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *create_shape_part(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();
    float radius = 3;

    sfCircleShape_setFillColor(circle, sfColor_fromRGB(200, 230, 210));
    sfCircleShape_setRadius(circle, radius);
    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_charging(void)
{
    anim_props_t *anim = create_anim_props(CHARGING, create_shape_part(),
        create_shape_start(), create_shape_end());
    return anim;
}

anim_t *create_charging(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_id(anim, CHARGING);
    anim_set_frequency(anim, 5);
    anim_set_batch_size(anim, 10);
    anim_set_duration(anim, 5);
    anim_set_speed(anim, 250);
    anim_set_scale(anim, (v2f_t){1, 2});
    anim_set_color(anim, sfColor_fromRGBA(230, 100, 100, 120));
    return anim;
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_rain
*/

#include "user.h"
#include "particle.h"
#include <stdlib.h>

static shape_t *start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){0, -10});
    sfRectangleShape_setSize(rect, (v2f_t){1200, 10});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 50));
    shape->type = RECT;
    shape->body.rect = rect;
    shape->is_default = false;
    return shape;
}

static shape_t *end(void)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = MIRROR;
    shape->body.offset = (v2f_t){-10, 650};
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_rain(void)
{
    return create_anim_props(RAIN, NULL, start(), end());
}

anim_t *create_rain(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_frequency(anim, 40);
    anim_set_batch_size(anim, 2);
    anim_set_duration(anim, 10);
    anim_set_speed(anim, 700);
    anim_set_scale(anim, (v2f_t){0.5, 2});
    anim_set_color(anim, sfColor_fromRGBA(60, 70, 100, 130));
    return anim;
}

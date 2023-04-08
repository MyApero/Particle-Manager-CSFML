/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_rain
*/

#include "user.h"
#include "particle.h"

static sfRectangleShape *create_shape_start(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){0, -10});
    sfRectangleShape_setSize(rect, (v2f_t){1200, 10});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 50));
    return rect;
}

anim_t *create_anim_rain(void)
{
    anim_t *anim = anim_create();

    anim_set_id(anim, RAIN);
    anim_set_frequency(anim, 40);
    anim_set_batch_size(anim, 2);
    anim_set_duration(anim, 10);
    anim_set_speed(anim, 700);
    anim_set_scale(anim, (v2f_t){0.5, 2});
    anim_set_color(anim, sfColor_fromRGBA(60, 70, 100, 130));
    anim_set_shape_start(anim, RECT, create_shape_start());
    anim_set_shape_end(anim, MIRROR, &(v2f_t){-150, 650});
    return anim;
}

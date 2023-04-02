/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** first_anims
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>

static sfRectangleShape *create_shape_start(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f){300, 400});
    sfRectangleShape_setSize(rect, (v2f){200, 50});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 0));
    return rect;
}

static sfRectangleShape *create_shape_end(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f){300, 200});
    sfRectangleShape_setSize(rect, (v2f){200, 50});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(230, 200, 180, 0));
    return rect;
}

anim_t *create_first_anim(void)
{
    anim_t *anim = anim_create();

    anim_set_id(anim, SMOKE);
    anim_set_frequency(anim, 200);
    anim_set_duration(anim, 1);
    anim_set_speed(anim, 100);
    anim_set_scale(anim, (v2f){0.2, 0.2});
    anim_set_color(anim, sfColor_fromRGBA(60, 70, 80, 160), sfColor_fromRGB(
        0, 0, 0));
    anim_set_shape_start(anim, RECT, create_shape_start());
    anim_set_shape_end(anim, RECT, create_shape_end());
    return anim;
}

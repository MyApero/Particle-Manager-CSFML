/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** first_anims
*/

#include "user.h"
#include "particle.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static shape_t *create_shape_start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){200, 200});
    sfRectangleShape_setSize(rect, (v2f_t){20, 20});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 2));
    shape->type = RECT;
    shape->body.rect = rect;
    shape->is_default = false;
    return shape;
}

static shape_t *create_shape_end(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (v2f_t){150, 150});
    sfCircleShape_setRadius(circle, 50);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(230, 200, 180, 2));
    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *create_shape_part(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();
    float radius = 5;

    sfCircleShape_setFillColor(circle, sfColor_fromRGB(200, 230, 210));
    sfCircleShape_setRadius(circle, radius);
    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_exp(void)
{
    anim_props_t *anim = create_anim_props(EXP, create_shape_part(),
        create_shape_start(), create_shape_end());
    return anim;
}

anim_t *create_exp(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_id(anim, EXP);
    anim_set_frequency(anim, 9);
    anim_set_batch_size(anim, 100);
    anim_set_duration(anim, 3);
    anim_set_speed(anim, 250);
    anim_set_scale(anim, (v2f_t){1, 1});
    anim_set_color(anim, sfColor_fromRGBA(200, 230, 210, 200));
    return anim;
}

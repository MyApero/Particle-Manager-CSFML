/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** third_anims
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static shape_t *create_shape_start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){500, 150});
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
    sfCircleShape_setRadius(circle, 100);
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
    float radius = 7;

    sfCircleShape_setOutlineThickness(circle, 3);
    sfCircleShape_setOutlineColor(circle, sfColor_fromRGB(10, 10, 50));
    sfCircleShape_setRadius(circle, radius);
    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_bubbles(void)
{
    anim_props_t *anim = create_anim_props(BUBBLES, create_shape_part(),
        create_shape_start(), create_shape_end());
    return anim;
}

anim_t *create_bubbles(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_frequency(anim, 1000);
    anim_set_duration(anim, 0.1);
    anim_set_speed(anim, 250);
    anim_set_scale(anim, (v2f_t){1, 1});
    anim_set_color(anim, sfColor_fromRGBA(77, 166, 255, 200));
    return anim;
}

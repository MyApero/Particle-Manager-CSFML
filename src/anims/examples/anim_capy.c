/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_capy
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static shape_t *create_shape_start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){300, 300});
    sfRectangleShape_setSize(rect, (v2f_t){10, 10});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 1));
    shape->type = RECT;
    shape->body.rect = rect;
    shape->is_default = false;
    return shape;
}

static shape_t *create_shape_end(sfSprite *sprite)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = SPRITE;
    shape->body.sprite = sprite;
    shape->is_default = false;
    return shape;
}

static shape_t *create_capy_sprite(sfTexture *txr)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, txr, false);
    shape->type = SPRITE;
    shape->body.sprite = sprite;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_capy(sfSprite *sprite, sfTexture *txr)
{
    anim_props_t *anim = create_anim_props(CAPY_ID, create_capy_sprite(txr),
        create_shape_start(), create_shape_end(sprite));
    anim->follow_dest = true;
    return anim;
}

anim_t *create_capy(anim_props_t *props, const sfTexture *txr)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim->particle_texture = txr;
    anim_set_id(anim, CAPY_ID);
    anim_set_frequency(anim, 200);
    anim_set_batch_size(anim, 4);
    anim_set_duration(anim, 0.1);
    anim_set_scale_modifier(anim, (v2f_t){1.03, 1.03}, (v2f_t){0.0, 0.0},
        (v2f_t){5.0, 5.0});
    anim_set_rotation(anim, 3);
    anim_set_speed(anim, 200);
    return anim;
}

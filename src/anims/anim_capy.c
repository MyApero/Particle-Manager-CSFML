/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_capy
*/

#include "user.h"
#include "particle.h"
#include <SFML/Graphics.h>

static sfRectangleShape *create_shape_start(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f){300, 300});
    sfRectangleShape_setSize(rect, (v2f){10, 10});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 1));
    return rect;
}

static sfRectangleShape *create_shape_end(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f){200, 200});
    sfRectangleShape_setSize(rect, (v2f){400, 210});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(230, 200, 180, 1));
    return rect;
}

static sfSprite *create_capy_sprite(anim_t *anim)
{
    sfSprite *sprite = sfSprite_create();
    anim->particle_texture = sfTexture_createFromFile(CAPY_PATH, NULL);

    sfSprite_setTexture(sprite, anim->particle_texture, FALSE);
    return sprite;
}

anim_t *create_anim_capy(void)
{
    anim_t *anim = anim_create();

    anim_set_id(anim, CAPY_ID);
    anim_set_frequency(anim, 200);
    anim_set_batch_size(anim, 4);
    anim_set_duration(anim, 0.1);
    anim_set_scale_modifier(anim, (v2f){1.03, 1.03} ,(v2f){0.0, 0.0},
        (v2f){100.0, 100.0});
    anim_set_rotation(anim, 100);
    anim_set_speed(anim, 100);
    anim_set_shape_part(anim, SPRITE, create_capy_sprite(anim));
    anim_set_shape_start(anim, RECT, create_shape_start());
    anim_set_shape_end(anim, RECT, create_shape_end());
    return anim;
}

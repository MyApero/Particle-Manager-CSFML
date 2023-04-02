/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>

static sfRectangleShape *create_default_shape(sfColor color, v2f size, v2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

static void set_anim_shapes(anim_t *anim)
{
    anim->particle_shape_default = sfTrue;
    anim->particle_shape_type = RECT;
    anim->particle_shape.rect = create_default_shape(anim->color_start,
    (v2f) {10, 10}, (v2f) {0, 0});
    anim->shape_start_default = sfTrue;
    anim->shape_start_type = RECT;
    anim->shape_start.rect = create_default_shape(anim->color_start,
    (v2f) {SHAPE_SIZE}, (v2f) {SHAPE_START});
    anim->shape_end_default = sfTrue;
    anim->shape_end_type = RECT;
    anim->shape_end.rect = create_default_shape(anim->color_end,
    (v2f) {SHAPE_SIZE}, (v2f) {SHAPE_END});
}

anim_t *anim_create(void)
{
    anim_t *anim = malloc(sizeof(anim_t));
    anim->particles = NULL;
    anim->color_start = sfWhite;
    anim->color_end = sfWhite;
    set_anim_shapes(anim);
    anim->speed = ANIM_SPEED;
    anim_set_frequency(anim, ANIM_FREQUENCY);
    anim->duration = ANIM_DURATION;
    anim->time_elapsed = 0;
    anim->scale = (v2f){ANIM_SCALE};
    anim->scale_modifier = (v2f){ANIM_SCALE};
    anim->scale_limit = (v2f){ANIM_SCALE};
    anim->rotation = 0;
    anim->is_generating = TRUE;
    anim->next = NULL;
    anim->previous = NULL;
    return anim;
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>

static sfRectangleShape *create_default_shape(sfColor color, v2f_t size, v2f_t pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

static void set_anim_shapes(anim_t *anim)
{
    anim->shape_part_default = sfTrue;
    anim->shape_part_type = RECT;
    anim->shape_part.rect = create_default_shape(anim->color,
        (v2f_t){10, 10}, (v2f_t){0, 0});
    anim->shape_start_default = sfTrue;
    anim->shape_start_type = RECT;
    anim->shape_start.rect = create_default_shape(anim->color,
        (v2f_t){SHAPE_SIZE}, (v2f_t){SHAPE_START});
    anim->shape_end_default = sfTrue;
    anim->shape_end_type = RECT;
    anim->shape_end.rect = create_default_shape(anim->color,
        (v2f_t){SHAPE_SIZE}, (v2f_t){SHAPE_END});
    anim->mirror_offset = (v2f_t){0, 0};
    anim->scale_props = NULL;
}

static void set_anim_properties(anim_t *anim)
{
    anim->speed = ANIM_SPEED;
    anim_set_frequency(anim, ANIM_FREQUENCY);
    anim->batch_size = ANIM_BATCH_SIZE;
    anim->duration = ANIM_DURATION;
    anim->time_elapsed = 0;
    anim->is_generating = true;
}

static void set_anim_particles(anim_t *anim)
{
    anim->particles = NULL;
    anim->particle_texture = NULL;
    anim->color = sfWhite;
    anim->scale = (v2f_t){ANIM_SCALE};
    anim->rotation = 0;
}

anim_t *anim_create(void)
{
    anim_t *anim = malloc(sizeof(anim_t));

    anim->id = 0;
    set_anim_particles(anim);
    set_anim_shapes(anim);
    set_anim_properties(anim);
    anim->next = NULL;
    anim->previous = NULL;
    return anim;
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>

static sfRectangleShape *create_default_shape(sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}

particles_t *particle_create(anim_t *anim)
{
    particles_t *particle = malloc(sizeof(particles_t));

    particle->color = anim->color_start;
    // particle->color_modifier = particle->color_start;
    particle->shape_type = RECT;
    particle->shape.rect = create_default_shape(particle->color);

    // shape_type_t shape_type;
    // shape_t shape;
    // v2f position;
    // v2f destination;
    // int speed;
    // float scale;
    // float scale_modifier;
    // float rotation_modifier;
    // sfColor color;
    // sfColor color_modifier;
    // double time_elapsed;
    // struct particles *next;

    // anim->particles = NULL;
    // anim->color_start = sfColor_fromRGBA(255, 0, 0, 150);
    // anim->color_end = anim->color_start;
    // anim->particle_shape_type = RECT;
    // anim->particle_shape.rect = create_default_shape(anim->color_start);
    // anim->shape_start_type = RECT;
    // anim->shape_start.rect = create_default_shape(anim->color_start);
    // anim->shape_end_type = RECT;
    // anim->shape_end.rect = create_default_shape(anim->color_start);
    // anim->speed = 1;
    // anim_set_frequency(anim, 2);
    // anim->duration = 3;
    // anim->scale = (v2f){1, 1};
    // anim->scale_modifier = 0;
    // anim->scale_limit = (v2f){1, 1};
    // anim->rotation = 0;
    // anim->is_generating = TRUE;
    return particle;
}

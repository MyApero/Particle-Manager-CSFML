/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>
#include <math.h>

static sfRectangleShape *create_default_shape(particles_t *particle)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, particle->position);
    sfRectangleShape_setSize(rect, (v2f){10, 10});
    sfRectangleShape_setFillColor(rect, particle->color);
    return rect;
}

static v2f set_movement(v2f spawn_pos, v2f dest, int speed)
{
    v2f direction = { dest.x - spawn_pos.x, dest.y - spawn_pos.y };
    float dir_norm = vector_norm(direction);
    return float_multiply_v2f(direction, 1 / dir_norm);
}

particles_t *particle_create(anim_t *anim)
{
    particles_t *particle = malloc(sizeof(particles_t));

    particle->color = anim->color_start;
    particle->position = particle_place_created(anim->shape_start,
    anim->shape_start_type);
    particle->destination = particle_place_created(anim->shape_end,
    anim->shape_end_type);
    particle->speed = anim->speed;
    particle->move = set_movement(particle->position, particle->destination,
    particle->speed);
    particle->shape_type = RECT;
    particle->shape.rect = create_default_shape(particle);
    particle->time_elapsed = 0;
    particle->next = NULL;
    return particle;
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>

static v2f set_movement(v2f spawn_pos, v2f dest, int speed)
{
    v2f direction = {dest.x - spawn_pos.x, dest.y - spawn_pos.y};

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
    set_shape_part(particle, anim);
    particle->time_elapsed = 0;
    particle->scale = anim->scale;
    particle->arrived = sfFalse;
    particle->next = NULL;
    return particle;
}

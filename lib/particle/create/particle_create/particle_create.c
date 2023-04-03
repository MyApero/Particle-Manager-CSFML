/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>
#include <math.h>

static v2f set_movement(v2f spawn_pos, v2f dest)
{
    v2f direction = {dest.x - spawn_pos.x, dest.y - spawn_pos.y};

    float dir_norm = vector_norm(direction);
    return float_multiply_v2f(direction, 1 / dir_norm);
}

static void set_destination(particles_t *part, anim_t *anim)
{
    if (anim->shape_end_type == MIRROR) {
        part->destination = (v2f){part->position.x + anim->mirror_offset.x,
            part->position.y + anim->mirror_offset.y};
    } else {
        part->destination = get_random_pos(anim->shape_end,
            anim->shape_end_type);
    }
}

particles_t *particle_create(anim_t *anim)
{
    particles_t *particle = malloc(sizeof(particles_t));

    particle->position = get_random_pos(anim->shape_start,
        anim->shape_start_type);
    set_shape_part(particle, anim);
    set_destination(particle, anim);
    particle->rotation_modifier = anim->rotation;
    particle->rota_no_change = anim->rotation;
    particle->color = anim->color;
    particle->scale_props = anim->scale_props;
    particle->move = set_movement(particle->position, particle->destination);
    particle->speed = anim->speed;
    particle->time_elapsed = 0;
    particle->arrived = sfFalse;
    particle->next = NULL;
    return particle;
}

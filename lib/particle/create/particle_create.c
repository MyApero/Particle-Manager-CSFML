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
    v2f direction = { dest.x - spawn_pos.x, dest.y - spawn_pos.y };
    float dir_norm = vector_norm(direction);
    return float_multiply_v2f(direction, 1 / dir_norm);
}

static void set_particle_shape(particles_t *part, anim_t *anim)
{
    part->shape_type = anim->particle_shape_type;
    switch (part->shape_type) {
    case 0 ... 1:
        part->shape.rect = sfRectangleShape_copy(anim->particle_shape.rect);
        sfRectangleShape_setPosition(part->shape.rect, part->position);
        sfRectangleShape_setFillColor(part->shape.rect, part->color);
        break;
    case 2 ... 3:
        part->shape.circle = sfCircleShape_copy(anim->particle_shape.circle);
        sfCircleShape_setPosition(part->shape.circle, part->position);
        sfCircleShape_setFillColor(part->shape.circle, part->color);
        break;
    };
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
    set_particle_shape(particle, anim);
    particle->time_elapsed = 0;
    particle->scale = anim->scale;
    particle->arrived = sfFalse;
    particle->next = NULL;
    return particle;
}

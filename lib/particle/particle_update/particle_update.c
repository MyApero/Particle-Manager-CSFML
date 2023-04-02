/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"

static void set_scale(shape_type_t shape_type, shape_t shape, v2f scale)
{
    if (shape_type == RECT || shape_type == RECT_OUTLINE)
        sfRectangleShape_setScale(shape.rect, scale);
    else if (shape_type == CIRCLE || shape_type == CIRCLE_OUTLINE)
        sfCircleShape_setScale(shape.circle, scale);
}

static void set_position(shape_type_t shape_type, shape_t shape, v2f pos)
{
    if (shape_type == RECT || shape_type == RECT_OUTLINE)
        sfRectangleShape_setPosition(shape.rect, pos);
    else if (shape_type == CIRCLE || shape_type == CIRCLE_OUTLINE)
        sfCircleShape_setPosition(shape.circle, pos);
}

static void apply_changes(particles_t *particle)
{
    set_position(particle->shape_type, particle->shape, particle->position);
    set_scale(particle->shape_type, particle->shape, particle->scale);
}

int particle_update(particles_t *particle, double dt)
{
    particles_t *next_particle;

    if (particle == NULL)
        return 0;
    if (particles_move_or_ended(particle, dt))
        return -1;
    particle->time_elapsed += dt;

    apply_changes(particle);
    return 0;
}
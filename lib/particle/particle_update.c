/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"

static void set_position(shape_type_t shape_type, shape_t shape, v2f pos)
{

    if (shape_type == RECT || shape_type == RECT_OUTLINE)
        sfRectangleShape_setPosition(shape.rect, pos);
    else if (shape_type == CIRCLE || shape_type == CIRCLE_OUTLINE)
        sfCircleShape_setPosition(shape.circle, pos);
}

void particle_update(particles_t *particle, double dt)
{
    particle->position.x += (rand() % 2) * particle->speed * dt;
    particle->position.y += (rand() % 2) * particle->speed * dt;
    particle->time_elapsed += dt;
    set_position(particle->shape_type, particle->shape, particle->position);
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"
#include "struct_particle.h"

static int is_particle_arrived(particles_t *part, v2f pos)
{
    if (sqrt(pow(part->position.x - part->destination.x, 2) +
    pow(part->position.y - part->destination.y, 2)) <= sqrt(pow(pos.y -
    part->destination.y, 2) + pow(pos.x - part->destination.x, 2)))
        return 1;
    return 0;
}

static int particles_move_or_ended(particles_t *part, double dt)
{
    v2f pos;

    if (part == NULL)
        return 0;
    pos.x = part->position.x + part->move.x * part->speed * dt;
    pos.y = part->position.y + part->move.y * part->speed * dt;
    if (is_particle_arrived(part, pos)) {
        // particle_destroy(part);
        return 1;
    }
    part->position = pos;
    return 0;
}

static void set_position(shape_type_t shape_type, shape_t shape, v2f pos)
{
    if (shape_type == RECT || shape_type == RECT_OUTLINE)
        sfRectangleShape_setPosition(shape.rect, pos);
    else if (shape_type == CIRCLE || shape_type == CIRCLE_OUTLINE)
        sfCircleShape_setPosition(shape.circle, pos);
}

int particle_update(particles_t *particle, double dt)
{
    particles_t *next_particle;

    if (particle == NULL)
        return 0;
    if (particles_move_or_ended(particle, dt))
        return -1;
    particle->time_elapsed += dt;
    set_position(particle->shape_type, particle->shape, particle->position);
    return 0;
}

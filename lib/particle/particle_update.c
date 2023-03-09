/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"
#include "struct_particle.h"

static int particles_move_or_ended(particles_t *prev, particles_t *part,
anim_t *anim, double dt)
{
    v2f pos;

    pos.x = part->position.x + part->moove.x * part->speed * dt;
    pos.y = part->position.y + part->moove.y * part->speed * dt;
    if (sqrt(pow(part->position.x - part->destination.x, 2) +
    pow(part->position.y - part->destination.y, 2)) <= sqrt(pow(pos.y -
    part->destination.y, 2) + pow(pos.x - part->destination.x, 2))) {
        part = particle_free(prev, part, anim);
        // printf("%p, %p\n", part, part->next);
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

void particle_update(particles_t *particle, particles_t *prev, anim_t *anim,
double dt)
{
    if (particles_move_or_ended(prev, particle, anim, dt))
        return;
    particle->time_elapsed += dt;
    set_position(particle->shape_type, particle->shape, particle->position);
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_render
*/

#include "particle.h"

static void append_particle(particles_t **particles, particles_t *new_particle)
{
    particles_t *particle = *particles;
    if (*particles == NULL) {
        *particles = new_particle;
        return;
    }
    for (; particle->next != NULL; particle = particle->next);
    particle->next = new_particle;
}

void anim_render(anim_t *animation, double dt)
{
    particles_t *particle = animation->particles;
    animation->spawn_delay -= dt;
    if (animation->spawn_delay < 0) {
        append_particle(&animation->particles, particle_create(animation));
        animation->spawn_delay = animation->spawn_delay_value;
    }
    for (; particle != NULL; particle = particle->next)
        animate_particle(particle, dt);
}

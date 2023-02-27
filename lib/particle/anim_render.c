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

void anim_render(anim_t *anim, double dt)
{
    particles_t *particle = anim->particles;
    anim->spawn_delay -= dt;
    anim->time_elapsed += dt;
    if (anim->time_elapsed < anim->duration && anim->spawn_delay < 0) {
        append_particle(&anim->particles, particle_create(anim));
        anim->spawn_delay = anim->spawn_delay_value;
    }
    for (; particle != NULL; particle = particle->next)
        animate_particle(particle, dt);
}

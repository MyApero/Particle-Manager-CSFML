/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_update
*/

#include "particle.h"
#include "struct_particle.h"
#include <SFML/Graphics/RectangleShape.h>

static void append_particle(anim_t *anim, particles_t **particles,
particles_t *new_particle)
{
    particles_t *particle = *particles;

    if (*particles == NULL) {
        *particles = new_particle;
        return;
    }
    for (; particle->next != NULL; particle = particle->next);
    particle->next = new_particle;
}

void anim_update(anim_t *anim, double dt)
{
    particles_t *particle = anim->particles;

    anim->spawn_delay -= dt;
    anim->time_elapsed += dt;
    if (anim->time_elapsed < anim->duration) {
        while (anim->spawn_delay < 0) {
            append_particle(anim, &anim->particles,
            particle_create(anim));
            anim->spawn_delay += anim->spawn_delay_value;
        }
    }
    if (particle == NULL && anim->time_elapsed > anim->duration) {
        anim_free(&anim);
        return;
    }
    for (particles_t *prev = particle; particle != NULL;
    prev = particle, particle = particle->next) {
        particle_update(particle, prev, anim, dt);
    }
}

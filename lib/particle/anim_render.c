/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_animation
*/

#include "particle.h"

void anim_render(anim_t *animation, double dt)
{
    particles_t *particle = animation->particles;
    animation->spawn_delay -= dt;
    if (animation->spawn_delay < 0) {
        particle_create(animation);
        animation->spawn_delay = animation->spawn_delay_value;
    }
    for (; particle != NULL; particle = particle->next)
        animate_particle(particle, dt);
}

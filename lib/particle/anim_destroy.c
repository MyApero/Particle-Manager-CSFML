/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_destroy
*/

#include "particle.h"
#include <stdlib.h>

static void destroy_particles(particles_t *particle)
{
    if (particle == NULL)
        return;
    destroy_particles(particle->next);
    destroy_shape(particle->shape_type, particle->shape);
    free(particle);
}

void anim_destroy(anim_t *animation)
{
    if (animation == NULL)
        return;
    destroy_particles(animation->particles);
    destroy_shape(animation->particle_shape_type, animation->particle_shape);
    destroy_shape(animation->shape_end_type, animation->shape_end);
    destroy_shape(animation->shape_start_type, animation->shape_start);
    free(animation);
}

/*
** EPITECH PROJECT, 2023
** lib/particle/particle_destroy
** File description:
** particle free
*/

#include "particle.h"
#include "struct_particle.h"

void particle_destroy(particles_t *particle)
{
    if (particle == NULL)
        return;
    destroy_shape(particle->shape_type, particle->shape);
    free(particle);
}

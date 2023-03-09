/*
** EPITECH PROJECT, 2023
** lib/particle/particle_free
** File description:
** particle free
*/

#include "particle.h"
#include "struct_particle.h"

particles_t *particle_free(particles_t *prev, particles_t *particle,
anim_t *anim)
{
    if (particle == NULL)
        return particle;
    if (prev == particle) {
        printf("la\n");
        anim->particles = prev->next;
        prev = prev->next;
    } else {
        printf("prev = %p, %p, part = %p, next = %p\n", prev,
            prev->next, particle, particle->next);
        prev->next = particle->next;
    }
    destroy_shape(particle->shape_type, particle->shape);
    free(particle);
    particle = prev;
    return prev;
}

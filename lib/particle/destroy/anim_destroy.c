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

void anim_destroy(anim_t *anim)
{
    if (anim == NULL)
        return;
    if (anim->previous != NULL)
        anim->previous->next = anim->next;
    if (anim->next != NULL)
        anim->next->previous = anim->previous;
    destroy_particles(anim->particles);
    destroy_shape(anim->shape_part_type, anim->shape_part);
    destroy_shape(anim->shape_end_type, anim->shape_end);
    destroy_shape(anim->shape_start_type, anim->shape_start);
    free(anim);
}

// Remove ended anims from the anim list, changing next and previous
void anim_destroy_secure(anim_t **anim_list, anim_t *anim)
{
    anim_t *next_anim = NULL;
    bool_t first_anim = FALSE;

    if (anim == NULL || !is_anim_ended(anim))
        return;
    if (anim->previous == NULL) {
        next_anim = anim->next;
        first_anim = TRUE;
    }
    anim_destroy(anim);
    if (first_anim) {
        anim = next_anim;
        *anim_list = anim;
    }
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_free
*/

#include "particle.h"
#include <stdlib.h>

static void destroy_shape(shape_type_t shape_type, shape_t shape)
{

    if (shape_type == RECT || shape_type == RECT_OUTLINE)
        sfRectangleShape_destroy(shape.rect);
    else if (shape_type == CIRCLE || shape_type == CIRCLE_OUTLINE)
        sfCircleShape_destroy(shape.circle);
}

static void free_particles(particles_t *particle)
{
    if (particle == NULL)
        return;
    free_particles(particle->next);
    destroy_shape(particle->shape_type, particle->shape);
    free(particle);
}

void anim_free(anim_t *animation)
{
    free_particles(animation->particles);
    destroy_shape(animation->particle_shape_type, animation->particle_shape);
    destroy_shape(animation->shape_end_type, animation->shape_end);
    destroy_shape(animation->shape_start_type, animation->shape_start);
    free(animation);
}

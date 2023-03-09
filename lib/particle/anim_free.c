/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_free
*/

#include "particle.h"
#include "struct_particle.h"
#include <stdlib.h>

void destroy_shape(shape_type_t shape_type, shape_t shape)
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
    particle = NULL;
}

void anim_free(anim_t **anim)
{
    anim_t *animation = *anim;

    free_particles(animation->particles);
    destroy_shape(animation->particle_shape_type, animation->particle_shape);
    destroy_shape(animation->shape_end_type, animation->shape_end);
    destroy_shape(animation->shape_start_type, animation->shape_start);
    free(animation);
    animation = NULL;
    *anim = animation;
}

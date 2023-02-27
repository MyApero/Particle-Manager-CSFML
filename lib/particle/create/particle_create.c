/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>

static sfRectangleShape *create_default_shape(particles_t *particle)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, particle->position);
    sfRectangleShape_setSize(rect, (v2f){10, 10});
    sfRectangleShape_setFillColor(rect, particle->color);
    return rect;
}

particles_t *particle_create(anim_t *anim)
{
    particles_t *particle = malloc(sizeof(particles_t));

    particle->color = anim->color_start;
    particle->position = (v2f){200, 200};
    particle->shape_type = RECT;
    particle->shape.rect = create_default_shape(particle);
    particle->speed = anim->speed;
    particle->time_elapsed = 0;
    particle->next = NULL;
    return particle;
}

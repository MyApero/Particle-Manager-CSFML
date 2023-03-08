/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>
#include <math.h>

static sfRectangleShape *create_default_shape(particles_t *particle)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, particle->position);
    sfRectangleShape_setSize(rect, (v2f){10, 10});
    sfRectangleShape_setFillColor(rect, particle->color);
    return rect;
}

static v2f particle_moove(particles_t *particle)
{
    v2f moove;
    int dist = sqrt(pow(particle->destination.x + particle->position.x,
    2) + pow(particle->destination.y + particle->position.y, 2));

    moove.x = ((particle->destination.x - particle->position.x) / dist);
    moove.y = ((particle->destination.y - particle->position.y) / dist);

    return moove;

}

particles_t *particle_create(anim_t *anim)
{
    particles_t *particle = malloc(sizeof(particles_t));

    particle->color = anim->color_start;
    particle->position = particle_place_created(anim->shape_start,
    anim->shape_start_type);
    particle->destination = particle_place_created(anim->shape_end,
    anim->shape_end_type);
    particle->moove = particle_moove(particle);
    particle->shape_type = RECT;
    particle->shape.rect = create_default_shape(particle);
    particle->speed = anim->speed;
    particle->time_elapsed = 0;
    particle->next = NULL;
    return particle;
}

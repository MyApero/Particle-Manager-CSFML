/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"

static void set_scale(shape_type_t shape_type, shape_t shape, v2f scale)
{
    switch (shape_type) {
    case RECT_OUTLINE: case RECT:
        sfRectangleShape_setScale(shape.rect, scale); break;
    case CIRCLE_OUTLINE: case CIRCLE:
        sfCircleShape_setScale(shape.circle, scale); break;
    case SPRITE:
        sfSprite_setScale(shape.sprite, scale); break;
    default:
        break;
    }
}

static void set_position(shape_type_t shape_type, shape_t shape, v2f pos)
{
    switch (shape_type) {
    case RECT_OUTLINE: case RECT:
        sfRectangleShape_setPosition(shape.rect, pos); break;
    case CIRCLE_OUTLINE: case CIRCLE:
        sfCircleShape_setPosition(shape.circle, pos); break;
    case SPRITE:
        sfSprite_setPosition(shape.sprite, pos); break;
    default:
        break;
    }
}

static void apply_changes(particles_t *particle)
{
    set_position(particle->shape_type, particle->shape, particle->position);
    set_scale(particle->shape_type, particle->shape, particle->scale);
}

int particle_update(particles_t *particle, double dt)
{
    particles_t *next_particle;

    if (particle == NULL)
        return 0;
    if (particles_move_or_ended(particle, dt))
        return -1;
    particle->time_elapsed += dt;

    apply_changes(particle);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"

static void set_scale(shape_type_t shape_type, shape_union_t shape,
scale_t **sca)
{
    v2f_t n_scale;
    scale_t *scale = *sca;

    if (*sca == NULL)
        return;
    switch (shape_type) {
        case RECT_OUTLINE: case RECT:
            sfRectangleShape_scale(shape.rect, scale->scale_modifier);
            n_scale = sfRectangleShape_getScale(shape.rect); break;
        case CIRCLE_OUTLINE: case CIRCLE:
            sfCircleShape_scale(shape.circle, scale->scale_modifier);
            n_scale = sfCircleShape_getScale(shape.circle); break;
        case SPRITE:
            sfSprite_scale(shape.sprite, scale->scale_modifier);
            n_scale = sfSprite_getScale(shape.sprite); break;
        default: return;
    }
    if (!contain_v2f(scale->scale_min, scale->scale_max, n_scale))
        scale->scale_modifier = (v2f_t){1.0, 1.0};
}

static void set_position(shape_type_t shape_type, shape_union_t shape,
v2f_t pos)
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

static void set_color(shape_type_t shape_type, shape_union_t shape,
particles_t *particle)
{
    switch (shape_type) {
        case RECT_OUTLINE: case RECT:
            sfRectangleShape_setFillColor(shape.rect, particle->color);
        case CIRCLE_OUTLINE: case CIRCLE:
            sfCircleShape_setFillColor(shape.circle, particle->color);
        default: break;
    }
}

static void apply_changes(particles_t *particle)
{
    set_position(particle->shape_type, particle->shape, particle->position);
    set_scale(particle->shape_type, particle->shape, &particle->scale_props);
    set_color(particle->shape_type, particle->shape, particle);
    set_rotation(particle->shape_type, particle->shape,
        particle->rotation_modifier);
}

int particle_update(particles_t *particle, double dt)
{
    particles_t *next_particle;

    if (particle == NULL)
        return 0;
    if (particles_move_or_ended(particle, dt))
        return -1;
    if (particle->anim->follow_destination) {
        set_destination(particle, particle->anim);
        particle->move = set_particle_movement(particle->position,
            particle->destination);
    }
    particle->time_elapsed += dt;
    apply_changes(particle);
    return 0;
}

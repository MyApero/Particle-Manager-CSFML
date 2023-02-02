/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** struct_particle
*/

#pragma once

#include "particle.h"

typedef sfVector2f v2f;

typedef enum boolean {
    FALSE,
    TRUE
} bool_t;

typedef enum shape_type {
    POINT,
    RECT,
    RECT_OUTLINE,
    CIRLCE,
    CIRCLE_OUTLINE
} shape_type_t;

typedef union shape {
    sfVector2f *point;
    sfRectangleShape *rect;
    sfCircleShape *circle;
} shape_t;

// @brief Here's all of the default values for this struct :
// @param particle_shape Rectangle 1:1:1:1
// @param start_shape Rectangle_outline 100:100:100:100
// @param end_shape Rectangle 145:145:10:10
// @param speed 1 (pixels/seconds)
// @param frequency 10 (per seconds)
// @param duration 2 (seconds)
// @param scale 1
// @param scale_modifier 1 (no negative, shrink < 1, grow > 1)
// @param scale_limit 1
// @param rotation 0
// @param color {255, 0, 0, 150}
typedef struct animation {
    shape_type_t particle_shape_type;
    shape_t particle_shape;
    shape_type_t start_shape_type;
    shape_t start_shape;
    shape_type_t end_shape_type;
    shape_t end_shape;
    int speed;
    int frequency;
    float duration;
    float scale;
    float scale_modifier;
    float scale_limit;
    float rotation;
    sfColor start_color;
    sfColor end_color;
} maAnim;

typedef struct particles {
    shape_type_t shape_type;
    shape_t shape;
    v2f position;
    v2f destination;
    int speed;
    float scale;
    float scale_modifier;
    float rotation_modifier;
    sfColor color;
    sfColor color_modifier;
} maParticles;

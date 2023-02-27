/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** struct_particle
*/

#pragma once

typedef sfVector2f v2f;

typedef enum boolean {
    FALSE,
    TRUE
} bool_t;

typedef enum shape_type {
    RECT,
    RECT_OUTLINE,
    CIRCLE,
    CIRCLE_OUTLINE
} shape_type_t;

typedef union shape {
    sfRectangleShape *rect;
    sfCircleShape *circle;
} shape_t;

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
    double time_elapsed;
    struct particles *next;
} particles_t;

// @brief Here's all of the default values for this struct :
// @param particle_shape Rectangle 1:1:1:1
// @param shape_start Rectangle_outline 100:100:100:100
// @param shape_end Rectangle 145:145:10:10
// @param speed 1 (pixels/seconds)
// @param frequency 10 (per seconds)
// @param duration 2 (seconds)
// @param scale 1
// @param scale_modifier 1 (no negative, shrink < 1, grow > 1)
// @param rotation 0
// @param color {255, 0, 0, 150}
typedef struct anim {
    particles_t *particles;
    shape_type_t particle_shape_type;
    shape_t particle_shape;
    shape_type_t shape_start_type;
    shape_t shape_start;
    shape_type_t shape_end_type;
    shape_t shape_end;
    int speed;
    double spawn_delay_value;
    double spawn_delay;
    float duration;
    v2f scale;
    float scale_modifier;
    v2f scale_limit;
    float rotation;
    sfColor color_start;
    sfColor color_end;
    bool_t is_generating;
} anim_t;

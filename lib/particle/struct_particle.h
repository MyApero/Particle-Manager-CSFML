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
    CIRCLE_OUTLINE,
    SPRITE,
    MIRROR
} shape_type_t;

typedef union shape {
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfSprite *sprite;
} shape_t;

typedef struct scale {
    v2f scale_modifier;
    v2f scale_min;
    v2f scale_max;
} scale_t;

typedef struct particles {
    shape_type_t shape_type;
    shape_t shape;
    v2f position;
    v2f destination;
    v2f move;
    int speed;
    scale_t *scale_props;
    float rotation_modifier;
    float rota_no_change;
    sfColor color;
    double time_elapsed;
    sfBool arrived;
    struct particles *next;
} particles_t;

// @brief Here's all of the default values for this struct :
// @param shape_part Rectangle 1:1:1:1
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
    int id;
    particles_t *particles;
    sfTexture *particle_texture;
    sfBool shape_part_default;
    shape_type_t shape_part_type;
    shape_t shape_part;
    sfBool shape_start_default;
    shape_type_t shape_start_type;
    shape_t shape_start;
    sfBool shape_end_default;
    shape_type_t shape_end_type;
    shape_t shape_end;
    v2f mirror_offset;
    int speed;
    double spawn_delay_value;
    double spawn_delay;
    unsigned int batch_size;
    float duration;
    double time_elapsed;
    v2f scale;
    scale_t *scale_props;
    float rotation;
    sfColor color;
    bool_t is_generating;
    struct anim *next;
    struct anim *previous;
} anim_t;

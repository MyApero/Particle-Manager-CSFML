/*
** EPITECH PROJECT, 2023
** include/struct_particle
** File description:
** structur for particle
*/

#pragma once

#include "particle.h"

typedef sfVector2f v2f;

typedef enum boolean {
    FALSE,
    TRUE
} bool_t;

typedef enum state {
    ALL,
    MENU,
    INGAME_MENU,
    GAME,
    FIGHT,
    DIALOG,
    GAME_END
} state_t;

typedef enum p_shape {
    POINT,
    RECT,
    CIRLCE,
    LINE
} p_shape_t;

typedef struct line {
    sfVector2f point1;
    sfVector2f point2;
} line_t;

typedef union shape_data {
    sfVector2f point;
    sfRectangleShape *rect;
    sfCircleShape *circle;
    line_t line;
} shape_data_t;

// @param int speed;
// @param int frequency;
// @param double life_time;
// @param p_shape_t start_shape;
// @param shape_data_t start_shape_data;
// @param p_shape_t end_shape;
// @param shape_data_t start_shape_data;
typedef struct particle_data {
    int speed;
    int frequency;
    double life_time;
    p_shape_t start_shape;
    shape_data_t start_shape_data;
    p_shape_t end_shape;
    shape_data_t start_shape_data;
} particle_data_t;

typedef struct animation {
    particle_data_t *particle_s;
    state_t state;
    struct animation *next;
} animation_t;

typedef struct game {
    bool_t running;
    animation_t *p_animations;
} game_t;

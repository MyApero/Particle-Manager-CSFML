/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test
*/

#pragma once

    #include "particle.h"

    #define WIDTH 1000
    #define HEIGHT 600
    #define FPS 60

    #define CAPY_PATH "assets/capy.png"

typedef enum anim_type {
    DEFAULT,
    SMOKE,
    EXP,
    BUBBLES,
    CAPY_ID
} anim_type_t;

void initialize(void);
anim_t *create_first_anim(void);
anim_t *create_second_anim(void);
anim_t *create_third_anim(void);
anim_t *create_anim_capy(void);

void free_anims(anim_t *anims);

void event_manager(sfRenderWindow *window, anim_t **anims);
void update_manager(anim_t **anims, double dt);
void draw_manager(sfRenderWindow *window, anim_t *anims);

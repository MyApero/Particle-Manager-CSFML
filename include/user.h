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
    CAPY_ID,
    RAIN,
    CHARGING
} anim_type_t;

void initialize(void);
anim_t *create_anim_smoke(void);
anim_t *create_anim_exp(void);
anim_t *create_anim_bubbles(void);
anim_t *create_anim_capy(void);
anim_t *create_anim_rain(void);
anim_t *create_anim_charging(void);

void free_anims(anim_t *anims);

void event_manager(sfRenderWindow *window, anim_t **anims);
void update_manager(anim_t **anims, double dt);
void draw_manager(sfRenderWindow *window, anim_t *anims);

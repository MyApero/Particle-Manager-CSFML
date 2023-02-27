/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test
*/

#pragma once

#define WIDTH 1000
#define HEIGHT 600
#define FPS 60

#include "particle.h"

typedef struct anim_list {
    anim_t *anim;
    struct anim_list *next;
} anim_list_t;

void initialize(void);
void free_anims(anim_list_t *anims);
anim_list_t *create_test_anims(void);
void event_manager(sfRenderWindow *window);
void render_manager(anim_list_t *anims, double dt);
void draw_manager(sfRenderWindow *window, anim_list_t *anims);


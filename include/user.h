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

void initialize(void);
void free_anims(anim_t *anims);
anim_t *create_first_anim(void);
void event_manager(sfRenderWindow *window);
void update_manager(anim_t *anims, double dt);
void draw_manager(sfRenderWindow *window, anim_t *anims);

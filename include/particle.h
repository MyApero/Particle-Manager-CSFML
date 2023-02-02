/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** particle
*/

#pragma once

#include "struct_particle.h"

/*-------------------------------INCLUDE--------------------------------------*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

/*------------------------------PROGRAMME-------------------------------------*/

anim_t *anim_create();
void anim_set_shape(anim_t *anim, shape_type_t shape_type, shape_t shape);
void anim_set_shape_start(anim_t *anim, shape_type_t shape_type, shape_t shape);
void anim_set_shape_end(anim_t *anim, shape_type_t shape_type, shape_t shape);
void anim_set_speed(anim_t *anim, int speed);
void anim_set_frequency(anim_t *anim, int frequency);
void anim_set_duration(anim_t *anim, float duration);
void anim_set_scale(anim_t *anim, float scale, float scale_modifier,
float scale_limit);
void anim_set_rotation(anim_t *anim, float rotation);
void anim_set_color(anim_t *anim, sfColor color, sfColor end_color);
void anim_set_rgb(anim_t *anim);
void animate_particles(anim_t *animation, double delta_time);
void anim_destroy(anim_t *animation);

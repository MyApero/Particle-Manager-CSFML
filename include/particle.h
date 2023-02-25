/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** particle
*/

#pragma once

/*-------------------------------INCLUDE--------------------------------------*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>

#include "struct_particle.h"

/*------------------------------PROGRAMME-------------------------------------*/

/*--------------------------------CREATE--------------------------------------*/

anim_t *anim_create(void);

/*-------------------------------SET_ANIM-------------------------------------*/

void anim_set_shape(anim_t *anim, shape_type_t shape_type, void *shape);
void anim_set_shape_start(anim_t *anim, shape_type_t shape_type, void *shape);
void anim_set_shape_end(anim_t *anim, shape_type_t shape_type, void *shape);
void anim_set_speed(anim_t *anim, int speed);
void anim_set_frequency(anim_t *anim, int frequency);
void anim_set_duration(anim_t *anim, float duration);
void anim_set_scale(anim_t *anim, sfVector2f scale);
void anim_set_scale_modifier(anim_t *anim, float scale_modifier);
void anim_set_scale_limit(anim_t *anim, sfVector2f scale_limit);
void anim_set_rotation(anim_t *anim, float rotation);
void anim_set_color(anim_t *anim, sfColor color_start, sfColor color_end);
void anim_set_rgb(anim_t *anim);

/*------------------------------PARTICLE_SET----------------------------------*/



/*----------------------------ANIMATE_PARTICLE--------------------------------*/

void animate_particles(anim_t *animation, double delta_time);

/*--------------------------------DESTROY-------------------------------------*/

void anim_destroy(anim_t *animation);

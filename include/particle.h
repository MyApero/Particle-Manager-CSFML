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

maAnim *maAnim_create();
void maAnim_setShape(maAnim *anim, shape_type_t shape_type, void *shape);
void maAnim_setShapeStart(maAnim *anim, shape_type_t shape_type, void *shape);
void maAnim_setShapeEnd(maAnim *anim, shape_type_t shape_type, void *shape);
void maAnim_setSpeed(maAnim *anim, int speed);
void maAnim_setFrequency(maAnim *anim, int frequency);
void maAnim_setDuration(maAnim *anim, float duration);
void maAnim_setScale(maAnim *anim, float scale, float scale_modifier,
float scale_limit);
void maAnim_setRotation(maAnim *anim, float rotation);
void maAnim_setColor(maAnim *anim, sfColor color, sfColor end_color);
void maAnim_setRGB(maAnim *anim);
maParticles *maParticles_create(maAnim *animation);
void maAnimate(maParticles *particles);
void maAnim_destroy(maAnim *animation);
void maParticles_destroy(maParticles *particles);

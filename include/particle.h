/*
** EPITECH PROJECT, 2023
** include/my
** File description:
** particle manager
*/

#pragma once
#include "struct_particle.h"

/*-------------------------------INCLUDE--------------------------------------*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

/*------------------------------PROGRAMME-------------------------------------*/

// @brief Creates an animation.
void create_particle_animation(particle_data_t *data);

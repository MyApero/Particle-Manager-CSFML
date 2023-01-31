/*
** EPITECH PROJECT, 2023
** include/struct_particule
** File description:
** structur for particule
*/

#pragma once

#include "particule.h"

typedef struct particule_s {
    double life_time;
    int intensity;
    vector2f start_position;
    vector2f end_position;
    int speedness; 
} particule_t;

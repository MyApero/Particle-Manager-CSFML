/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_frequency
** File description:
** set frequency of the apparition of particules
*/

#include "particle.h"

void anim_set_frequency(anim_t *anim, int frequency)
{
    anim->frequency = frequency;
}

/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_color
** File description:
** set color start and end
*/

#include "particle.h"

void anim_set_color(anim_t *anim, sfColor color_start, sfColor color_end)
{
    anim->color_start = color_start;
    anim->color_end = color_end;
}

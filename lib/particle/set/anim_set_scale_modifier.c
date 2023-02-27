/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_scale_modifier
** File description:
** set scale modifier
*/

#include "particle.h"

void anim_set_scale_modifier(anim_t *anim, v2f scale_modifier)
{
    anim->scale_modifier = scale_modifier;
}

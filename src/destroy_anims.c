/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** free_anims
*/

#include "user.h"
#include <stdlib.h>

void free_anims(anim_t *anim)
{
    if (anim == NULL)
        return;
    free_anims(anim->next);
    anim_destroy(anim);
}

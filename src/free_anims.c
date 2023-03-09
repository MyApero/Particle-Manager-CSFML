/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** free_anims
*/

#include "../include/user.h"
#include <stdlib.h>

void free_anims(anim_list_t *anims)
{
    if (anims == NULL)
        return;
    free_anims(anims->next);
    anim_free(&anims->anim);
    free(anims);
}

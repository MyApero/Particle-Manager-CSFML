/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_game
*/

#include "../include/user.h"
#include <stdlib.h>

void update_manager(anim_t **anims, double dt)
{
    anim_t *anim = *anims;
    anim_t *next_anim = NULL;

    if (anims == NULL)
        return;
    for (; anim != NULL; anim = next_anim) {
        next_anim = anim->next;
        if (anim->id == EXP)
            anim_set_color(anim, sfColor_fromRGBA(rand() % 255, 200,
                100, 180), sfColor_fromRGB(0, 0, 0));
        anim_update(anim, dt);
        anim_destroy_secure(anims, anim);
    }
}

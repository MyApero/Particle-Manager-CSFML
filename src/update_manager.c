/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_game
*/

#include "../include/user.h"

void update_manager(anim_t *anims, double dt)
{
    for (anim_t *anim = anims; anim != NULL; anim = anim->next) {
        anim_set_color(anim, sfColor_fromRGBA(rand() % 255, rand() % 255,
            rand() % 255, 150), sfColor_fromRGB(0, 0, 0));
        anim_update(anim, dt);
    }
}

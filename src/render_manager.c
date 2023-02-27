/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_game
*/

#include "../include/user.h"

void render_manager(anim_list_t *anims, double dt)
{
    anim_set_color(anims->anim, sfColor_fromRGBA(rand() % 255, rand() % 255,
        rand() % 255, 150), sfColor_fromRGB(0, 0, 0));
    for (; anims != NULL; anims = anims->next) {
        anim_render(anims->anim, dt);
    }
}

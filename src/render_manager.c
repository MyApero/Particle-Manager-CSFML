/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_game
*/

#include "../include/user.h"

void render_manager(anim_list_t *anims, double dt)
{
    for (; anims != NULL; anims = anims->next) {
        anim_render(anims->anim, dt);
    }
}

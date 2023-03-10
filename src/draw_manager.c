/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** draw_manager
*/

#include "../include/user.h"

void draw_manager(sfRenderWindow *window, anim_t *anims)
{
    sfRenderWindow_clear(window, sfBlack);
    for (anim_t *anim = anims; anim != NULL; anim = anim->next) {
        anim_display(window, anim);
    }
    sfRenderWindow_display(window);
}

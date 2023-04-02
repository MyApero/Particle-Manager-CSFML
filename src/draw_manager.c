/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** draw_manager
*/

#include "../include/user.h"

void draw_manager(sfRenderWindow *window, anim_t *anims)
{
    anim_t *anim = anims;

    sfRenderWindow_clear(window, sfBlack);
    for (; anim != NULL; anim = anim->next) {
        anim_draw(window, anim);
    }
    sfRenderWindow_display(window);
}

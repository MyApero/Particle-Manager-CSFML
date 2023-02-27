/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** draw_manager
*/

#include "../include/user.h"

void draw_manager(sfRenderWindow *window, anim_list_t *anims)
{
    sfRenderWindow_clear(window, sfBlack);
    for (; anims != NULL; anims = anims->next) {
        anim_display(window, anims->anim);
    }
    sfRenderWindow_display(window);
}

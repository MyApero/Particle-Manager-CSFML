/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** draw_manager
*/

#include "user.h"

void draw_manager(sfRenderWindow *window, anim_t *anims, sfSprite *capy)
{
    anim_t *anim = anims;

    sfRenderWindow_clear(window, sfBlack);
    for (; anim != NULL; anim = anim->next) {
        anim_draw(window, anim);
    }
    sfRenderWindow_drawSprite(window, capy, NULL);
    sfRenderWindow_display(window);
}

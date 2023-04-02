/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** event_manager
*/

#include "../include/user.h"

static void manage_keys(sfKeyCode key, anim_t **anims)
{
    if (key == sfKeyA) {
        anim_append(anims, create_first_anim());
    } if (key == sfKeyZ) {
        anim_append(anims, create_second_anim());
    } if (key == sfKeyE) {
        anim_append(anims, create_third_anim());
    } if (key == sfKeyR) {
        anim_append(anims, create_anim_capy());
    }
}

void event_manager(sfRenderWindow *window, anim_t **anims)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            manage_keys(event.key.code, anims);
    }
}

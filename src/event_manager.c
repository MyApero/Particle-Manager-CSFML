/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** event_manager
*/

#include "../include/user.h"
#include <SFML/System.h>
#include <stdio.h>

static void manage_keys(sfKeyCode key, anim_t **anims)
{
    if (key == sfKeyA) {
        anim_append(anims, create_anim_smoke());
    } if (key == sfKeyZ) {
        anim_append(anims, create_anim_exp());
    } if (key == sfKeyE) {
        anim_append(anims, create_anim_bubbles());
    } if (key == sfKeyR) {
        anim_append(anims, create_anim_capy());
    } if (key == sfKeyT) {
        anim_append(anims, create_anim_rain());
    } if (key == sfKeyY) {
        anim_append(anims, create_anim_charging());
    }
}

void event_manager(sfRenderWindow *window, anim_t **anims)
{
    sfEvent event;
    sfVector2i mpos;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            manage_keys(event.key.code, anims);
        if (event.type == sfEvtMouseButtonPressed) {
            mpos = sfMouse_getPositionRenderWindow(window);
            printf("mouse down x%d y%d\n", mpos.x, mpos.y);
        }
    }
}

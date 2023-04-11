/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** event_manager
*/

#include "user.h"
#include <SFML/System.h>
#include <stdio.h>

static void manage_keys(sfKeyCode key, anim_t **anims, sfSprite *capy,
anim_props_t *anims_props)
{
    if (key == sfKeyA)
        anim_append(anims, create_smoke(get_anims_props(anims_props, SMOKE)));
    if (key == sfKeyZ)
        anim_append(anims, create_exp(get_anims_props(anims_props, EXP)));
    if (key == sfKeyE)
        anim_append(anims, create_bubbles(get_anims_props(anims_props,
            BUBBLES)));
    if (key == sfKeyR)
        anim_append(anims, create_capy(get_anims_props(anims_props, CAPY_ID),
            sfSprite_getTexture(capy)));
    if (key == sfKeyT)
        anim_append(anims, create_rain(get_anims_props(anims_props, RAIN)));
    if (key == sfKeyY)
        anim_append(anims, create_charging(get_anims_props(anims_props,
            CHARGING)));
}

void event_manager(sfRenderWindow *window, anim_t **anims, sfSprite *capy,
anim_props_t *anims_props)
{
    sfEvent event;
    sfVector2i mpos;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            manage_keys(event.key.code, anims, capy, anims_props);
        if (event.type == sfEvtMouseButtonPressed) {
            mpos = sfMouse_getPositionRenderWindow(window);
            printf("mouse down x%d y%d\n", mpos.x, mpos.y);
        }
    }
}

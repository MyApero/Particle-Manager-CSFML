/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** event_manager
*/

#include "../include/user.h"

void event_manager(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
    }
}

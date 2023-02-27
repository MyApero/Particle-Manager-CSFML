/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_animation
*/

#include "particle.h"

void anim_display(sfRenderWindow *win, anim_t *animation)
{
    particles_t *particle = animation->particles;
    for (; particle != NULL; particle = particle->next) {
        if (particle->shape_type == RECT)
            sfRenderWindow_drawRectangleShape(win, particle->shape.rect, NULL);
        if (particle->shape_type == CIRCLE)
            sfRenderWindow_drawCircleShape(win, particle->shape.circle, NULL);
    }
}

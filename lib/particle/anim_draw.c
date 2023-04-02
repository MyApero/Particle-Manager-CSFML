/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_animation
*/

#include "particle.h"
#include <SFML/Graphics/RenderWindow.h>

void anim_draw(sfRenderWindow *win, anim_t *animation)
{
    particles_t *particle;

    if (animation == NULL)
        return;
    particle = animation->particles;
    sfRenderWindow_drawRectangleShape(win, animation->shape_start.rect, NULL);
    sfRenderWindow_drawRectangleShape(win, animation->shape_end.rect, NULL);
    for (; particle != NULL; particle = particle->next) {
        if (particle->arrived)
            continue;
        if (particle->shape_type == RECT)
            sfRenderWindow_drawRectangleShape(win, particle->shape.rect, NULL);
        if (particle->shape_type == CIRCLE)
            sfRenderWindow_drawCircleShape(win, particle->shape.circle, NULL);
    }
}

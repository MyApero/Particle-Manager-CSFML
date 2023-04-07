/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_game
*/

#include "../include/user.h"
#include <stdlib.h>

static void enhance_anim(anim_t *anim)
{
    v2f scale;

    switch (anim->id) {
    case EXP:
        anim_set_color(anim, sfColor_fromRGBA(rand() % 255, 200,
            100, 180), sfColor_fromRGB(0, 0, 0));
        sfRectangleShape_move(anim->shape_start.rect, (v2f){1, 1});
        break;
    case RAIN:
        anim_set_speed(anim, get_random_nb_between(anim->speed, 500, 999, 50));
        scale.x = (float)get_random_nb_between(30, 10, 40, 10) / 100;
        scale.y = (float)get_random_nb_between(200, 50, 400, 10) / 100;
        anim_set_scale(anim, scale);
        break;
    default:
        break;
    }
}

void update_manager(anim_t **anims, double dt)
{
    anim_t *anim = *anims;
    anim_t *next_anim = NULL;

    if (anims == NULL)
        return;
    for (; anim != NULL; anim = next_anim) {
        next_anim = anim->next;
        enhance_anim(anim);
        anim_update(anim, dt);
        anim_destroy_secure(anims, anim);
    }
}

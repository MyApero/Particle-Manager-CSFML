/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_game
*/

#include "user.h"
#include <stdlib.h>

static void enhance_anim(anim_t *anim, sfRenderWindow *wd, sfSprite *capy)
{
    v2f_t scale;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(wd);
    v2f_t mpos_f = {mpos.x, mpos.y};

    sfSprite_setPosition(capy, mpos_f);
    switch (anim->id) {
    case EXP:
        anim_set_color(anim, sfColor_fromRGBA(rand() % 255, 200, 100, 180));
        break;
    case RAIN:
        anim_set_speed(anim, get_random_nb_between(anim->speed, 500, 999, 50));
        scale.x = (float)get_random_nb_between(30, 10, 40, 10) / 100;
        scale.y = (float)get_random_nb_between(200, 50, 400, 10) / 100;
        anim_set_scale(anim, scale);
        break;
    case CHARGING:
        sfCircleShape_setPosition(anim->shape_end->body.circle, mpos_f);
        break;
    default: break;
    }
}

void update_manager(anim_t **anims, double dt, sfRenderWindow *wd,
sfSprite *capy)
{
    anim_t *anim = *anims;
    anim_t *next_anim = NULL;

    if (anims == NULL)
        return;
    for (; anim != NULL; anim = next_anim) {
        next_anim = anim->next;
        enhance_anim(anim, wd, capy);
        anim_update(anim, dt);
        anim_destroy_secure(anims, anim);
    }
}

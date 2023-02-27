/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test_anims
*/

#include "../include/user.h"
#include "../include/particle.h"
#include <stdlib.h>

anim_t *create_first_anim(void)
{
    anim_t *anim = anim_create();
    anim_set_duration(anim, 3.5);
    anim_set_frequency(anim, 1000);
    anim_set_duration(anim, 3);
    anim_set_speed(anim, 300);
    anim_set_color(anim, sfColor_fromRGBA(200, 200, 30, 100), sfColor_fromRGB(
        0, 0, 0));
    return anim;
}

anim_list_t *create_test_anims(void)
{
    anim_list_t *anims = malloc(sizeof(anim_list_t));
    anims->anim = create_first_anim();
    anims->next = NULL;
    return anims;
}

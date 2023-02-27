/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test_anims
*/

#include "../include/test.h"
#include "../include/particle.h"
#include <stdlib.h>

anim_t *create_first_anim(void)
{
    anim_t *anim = anim_create();
    anim_set_duration(anim, 3.5);
    return anim;
}

anim_list_t *create_test_anims(void)
{
    anim_list_t *anims = malloc(sizeof(anim_list_t));
    anims->anim = create_first_anim();
    anims->next = NULL;
    return anims;
}

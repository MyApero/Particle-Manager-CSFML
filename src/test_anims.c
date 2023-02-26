/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test_anims
*/

#include "../include/test.h"
#include "../include/particle.h"
#include <stdlib.h>

anim_list_t *create_test_anims(void)
{
    anim_list_t *anims = malloc(sizeof(anim_list_t));
    anims->anim = anim_create();
    anims->next = NULL;
    return anims;
}

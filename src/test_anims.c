/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test_anims
*/

#include "../include/user.h"
#include "../include/particle.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <stdlib.h>

anim_t *create_first_anim(void)
{
    anim_t *anim = anim_create();

    anim_set_duration(anim, 3);
    anim_set_frequency(anim, 200);
    anim_set_duration(anim, 3);
    anim_set_speed(anim, 300);
    anim_set_color(anim, sfColor_fromRGBA(200, 200, 30, 100), sfColor_fromRGB(
        0, 0, 0));
    return anim;
}

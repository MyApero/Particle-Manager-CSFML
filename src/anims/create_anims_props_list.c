/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_anim_props
*/

#include "user.h"
#include <stdlib.h>

anim_props_t *create_anims_props_list(void)
{
    anim_props_t *anim_props = NULL;

    append_anim_props(&anim_props, create_anim_props_smoke());
    append_anim_props(&anim_props, create_anim_props_rain());
    append_anim_props(&anim_props, create_anim_props_exp());
    append_anim_props(&anim_props, create_anim_props_charging());
    append_anim_props(&anim_props, create_anim_props_bubbles());

    return anim_props;
}

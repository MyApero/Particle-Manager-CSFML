/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** get_anims_props
*/

#include "user.h"

anim_props_t *get_anims_props(anim_props_t *anims_props, anim_type_t id)
{
    if (anims_props == NULL)
        return NULL;
    for (; anims_props != NULL; anims_props = anims_props->next)
        if (anims_props->type == id)
            return anims_props;
    return NULL;
}

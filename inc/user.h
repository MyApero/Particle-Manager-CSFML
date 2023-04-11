/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** test
*/

#pragma once

    #include "particle.h"

    #define WIDTH 1000
    #define HEIGHT 600
    #define FPS 60

    #define CAPY_PATH "assets/capy.png"

typedef enum anim_type {
    DEFAULT,
    SMOKE,
    EXP,
    BUBBLES,
    CAPY_ID,
    RAIN,
    CHARGING
} anim_type_t;

typedef struct anim_props {
    anim_type_t type;
    shape_t *shape_part;
    shape_t *shape_start;
    shape_t *shape_end;
    bool follow_dest;
    struct anim_props *next;
} anim_props_t;

void initialize(void);
anim_props_t *create_anim_props_smoke(void);
anim_t *create_smoke(anim_props_t *props);
anim_props_t *create_anim_props_exp(void);
anim_t *create_exp(anim_props_t *props);
anim_props_t *create_anim_props_bubbles(void);
anim_t *create_bubbles(anim_props_t *props);
anim_props_t *create_anim_props_capy(sfSprite *sprite, sfTexture *txr);
anim_t *create_capy(anim_props_t *props, const sfTexture *txr);
anim_props_t *create_anim_props_rain(void);
anim_t *create_rain(anim_props_t *props);
anim_props_t *create_anim_props_charging(void);
anim_t *create_charging(anim_props_t *props);

anim_props_t *create_anims_props_list(void);
void append_anim_props(anim_props_t **anim_props, anim_props_t *to_add);
anim_props_t *create_anim_props(anim_type_t type, shape_t *shape_part,
shape_t *shape_start, shape_t *shape_end);
void set_anim_props(anim_t *anim, anim_props_t *props);
anim_props_t *get_anims_props(anim_props_t *anims_props, anim_type_t id);
void destroy_anims_props(anim_props_t *anims_props);

void free_anims(anim_t *anims);

void event_manager(sfRenderWindow *window, anim_t **anims, sfSprite *capy,
anim_props_t *anims_props);
void update_manager(anim_t **anims, double dt, sfRenderWindow *wd,
sfSprite *capy);
void draw_manager(sfRenderWindow *window, anim_t *anims, sfSprite *capy);

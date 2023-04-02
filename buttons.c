/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** buttons
*/

typedef struct rpg {
    int game;
} rpg_t;

typedef enum button_state {
    NONE,
    HOVER,
    PRESSED,
    RELEASED
} button_state_t;

typedef struct button {
    button_state_t state;
    void (*action)(rpg_t *rpg);
} button_t;

Event :
    Si event, changer le state du bouton
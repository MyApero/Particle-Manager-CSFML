/*
** EPITECH PROJECT, 2023
** particle
** File description:
** gestion of particle
*/


// #include "particle.h"
#include <stdio.h>
#include <SFML/Graphics.h>

typedef enum type {
    RECT,
    CIRCLE
} type_t;

typedef union my_union {
    void *m;
    int *a;
    float b;
    struct {
        char c;
        char d;
        char e;
        char f;
    };
} my_union_t;

void my_function(void *my_parameter)
{
    my_union_t my_union;
    my_union.m = my_parameter;
    printf("a: %d, e: %c, b: %f\n", *my_union.a, my_union.e, my_union.b);
}

int main(void)
{
    int a = 800;
    float b = 3;

    my_function(&a);

    return 0;
}

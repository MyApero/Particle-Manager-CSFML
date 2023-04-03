/*
** EPITECH PROJECT, 2022
** v2f_operations
** File description:
** v2f_operations
*/

#include "particle.h"

v2f float_multiply_v2f(v2f v, float x)
{
    v2f new_v;

    new_v.x = v.x * x;
    new_v.y = v.y * x;
    return new_v;
}

v2f add_two_v2f(v2f v1, v2f v2)
{
    v2f new_v;

    new_v.x = v1.x + v2.x;
    new_v.y = v1.y + v2.y;
    return new_v;
}

int contain_v2f(v2f min, v2f max, v2f ele)
{
    if (ele.x >= min.x && ele.x <= max.x && ele.y >= min.y && ele.y <= max.y)
        return 1;
    return 0;
}

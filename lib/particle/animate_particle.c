/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** animate_particle
*/

#include "particle.h"

void animate_particle(particles_t *particle, double dt)
{
    particle->position.x += 50 * dt;
}

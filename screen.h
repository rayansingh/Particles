// screen.h - Defines related to SDL display
//

#ifndef SCREEN_H
#define SCREEN_H

#include "particle.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

#define HORIZONTAL_PARTICLES (SCREEN_WIDTH/PARTICLE_SIZE)
#define VERTICAL_PARTICLES (SCREEN_HEIGHT/PARTICLE_SIZE)

extern Particle* grid[VERTICAL_PARTICLES][HORIZONTAL_PARTICLES];

// Size of cursor when spawning particles
extern uint8_t cursor_radius;

void init_screen();
void update();
void refresh(SDL_Renderer* renderer);
void insert_particle(int32_t x, int32_t y);
void insert_particle(int32_t x, int32_t y, particle_type_t type);
void set_particle(particle_type_t type);

#endif // SCREEN_H

// screen.h - Defines related to SDL display
//

#ifndef SCREEN_H
#define SCREEN_H

#include "particle.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

#define HORIZONTAL_PARTICLES (SCREEN_WIDTH/PARTICLE_SIZE)
#define VERTICAL_PARTICLES (SCREEN_HEIGHT/PARTICLE_SIZE)

extern struct particle grid[VERTICAL_PARTICLES][HORIZONTAL_PARTICLES];

void init_screen();
void update();
void refresh(SDL_Renderer* renderer);
void insert_particle(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif // SCREEN_H

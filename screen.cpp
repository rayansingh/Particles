// screen.c - Functions defined in screen.h
//

#include "screen.h"
#include <iostream>

Particle* grid[VERTICAL_PARTICLES][HORIZONTAL_PARTICLES];

void init_screen() {
    for (uint32_t r = 0; r < (uint32_t)VERTICAL_PARTICLES; r++) {
        for (uint32_t c = 0; c < (uint32_t)HORIZONTAL_PARTICLES; c++) {
            grid[r][c] = nullptr;
        }
    }
}

void update() {
    for (int32_t r = (int32_t)VERTICAL_PARTICLES-2; r >= 0; r--) {
        for (uint32_t c = 0; c < (uint32_t)HORIZONTAL_PARTICLES; c++) {

            Particle **p_a, **p_b;

            if (rand() % 2) {
                p_a = c > 0 ? &grid[r+1][c-1] : nullptr;
                p_b = c < (uint32_t)HORIZONTAL_PARTICLES-1 ? &grid[r+1][c+1] : nullptr;
            } else {
                p_a = c < (uint32_t)HORIZONTAL_PARTICLES-1 ? &grid[r+1][c+1] : nullptr;
                p_b = c > 0 ? &grid[r+1][c-1] : nullptr;
            }

            if (grid[r][c] != nullptr) {
                if (grid[r+1][c] == nullptr) {
                    grid[r+1][c] = grid[r][c];
                    grid[r][c] = nullptr;
                } else if (*p_a == nullptr) {
                    *p_a = grid[r][c];
                    grid[r][c] = nullptr;
                } else if (*p_b == nullptr) {
                    *p_b = grid[r][c];
                    grid[r][c] = nullptr;
                }
            }
        }
    }
}

void refresh(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (uint32_t r = 0; r < (uint32_t)VERTICAL_PARTICLES; r++) {
        for (uint32_t c = 0; c < (uint32_t)HORIZONTAL_PARTICLES; c++) {
            if (grid[r][c] != nullptr) {
                for (uint8_t y = 0; y < PARTICLE_SIZE; y++) {
                    for (uint8_t x = 0; x < PARTICLE_SIZE; x++) {
                        SDL_Color color = grid[r][c]->color;
                        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                        SDL_RenderDrawPoint(renderer, c*PARTICLE_SIZE+x,r*PARTICLE_SIZE+y);
                    }
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void insert_particle(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    if (x < 0 || x >= HORIZONTAL_PARTICLES || y < 0 || y >= VERTICAL_PARTICLES) {
        return;
    }
    grid[y][x] = new Particle(r,g,b,a);
}

// screen.c - Functions defined in screen.h
//

#include "screen.h"
#include "sand.h"
#include <iostream>

Particle* grid[VERTICAL_PARTICLES][HORIZONTAL_PARTICLES];
uint8_t cursor_radius = 2;

void init_screen() {
    for (int32_t r = 0; r < (int32_t)VERTICAL_PARTICLES; r++) {
        for (int32_t c = 0; c < (int32_t)HORIZONTAL_PARTICLES; c++) {
            grid[r][c] = nullptr;
        }
    }
}

void update() {
    for (int32_t r = (int32_t)VERTICAL_PARTICLES-2; r >= 0; r--) {
        for (int32_t c = 0; c < (int32_t)HORIZONTAL_PARTICLES; c++) {

            Particle **p_a, **p_b;

            if (rand() % 2) {
                p_a = c > 0 ? &grid[r+1][c-1] : nullptr;
                p_b = c < (int32_t)HORIZONTAL_PARTICLES-1 ? &grid[r+1][c+1] : nullptr;
            } else {
                p_a = c < (int32_t)HORIZONTAL_PARTICLES-1 ? &grid[r+1][c+1] : nullptr;
                p_b = c > 0 ? &grid[r+1][c-1] : nullptr;
            }

            if (grid[r][c] != nullptr) {
                if (grid[r+1][c] == nullptr) {
                    grid[r+1][c] = grid[r][c];
                    grid[r][c] = nullptr;
                } else if (p_a != nullptr && *p_a == nullptr) {
                    *p_a = grid[r][c];
                    grid[r][c] = nullptr;
                } else if (p_b != nullptr && *p_b == nullptr) {
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

    for (int32_t r = 0; r < (int32_t)VERTICAL_PARTICLES; r++) {
        for (int32_t c = 0; c < (int32_t)HORIZONTAL_PARTICLES; c++) {
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

void insert_particle(int32_t x, int32_t y) {
    for (int32_t i = y-cursor_radius; i < y+cursor_radius; i++) {
        for (int32_t j = x-cursor_radius; j < x+cursor_radius; j++) {
            if (i >= 0 && i < VERTICAL_PARTICLES
                && j >= 0 && j < HORIZONTAL_PARTICLES && grid[y][x] == nullptr
                && sqrt(pow((i-y),2)+pow((j-x),2)) < cursor_radius
                && rand()%4 == 1) {
                grid[i][j] = new Sand();
            }
        }
    }
}

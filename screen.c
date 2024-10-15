// screen.c - Functions defined in screen.h
//

#include "screen.h"

struct particle grid[VERTICAL_PARTICLES][HORIZONTAL_PARTICLES];

void init_screen() {
    for (uint32_t r = 0; r < (uint32_t)VERTICAL_PARTICLES; r++) {
        for (uint32_t c = 0; c < (uint32_t)HORIZONTAL_PARTICLES; c++) {
            grid[r][c].is = 0;
            grid[r][c].c = (SDL_Color){0,0,0,0};
        }
    }
}

void update() {
    for (int32_t r = (int32_t)VERTICAL_PARTICLES-2; r >= 0; r--) {
        for (uint32_t c = 1; c < (uint32_t)HORIZONTAL_PARTICLES; c++) {

            struct particle *p_a, *p_b;

            if (rand() % 2) {
                p_a = &grid[r+1][c-1];
                p_b = &grid[r+1][c+1];
            } else {
                p_a = &grid[r+1][c+1];
                p_b = &grid[r+1][c-1];
            }

            if (grid[r][c].is) {
                if (!grid[r+1][c].is) {
                    grid[r+1][c] = grid[r][c];
                    grid[r][c].is = 0;
                    grid[r][c].c = (SDL_Color){0,0,0,0};
                } else if (!p_a->is) {
                    *p_a = grid[r][c];
                    grid[r][c].is = 0;
                    grid[r][c].c = (SDL_Color){0,0,0,0};
                } else if (!p_b->is) {
                    *p_b = grid[r][c];
                    grid[r][c].is = 0;
                    grid[r][c].c = (SDL_Color){0,0,0,0};
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
            if (grid[r][c].is) {
                for (uint8_t y = 0; y < PARTICLE_SIZE; y++) {
                    for (uint8_t x = 0; x < PARTICLE_SIZE; x++) {
                        SDL_Color color = grid[r][c].c;
                        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                        SDL_RenderDrawPoint(renderer, c*PARTICLE_SIZE+x,r*PARTICLE_SIZE+y);
                    }
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void insert_particle(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    grid[y][x].is = 1;
    grid[y][x].c = (SDL_Color){r,g,b,a};
}

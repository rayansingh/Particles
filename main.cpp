#include "particle.h"
#include "screen.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main() {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,0,&window,&renderer);

    SDL_RenderClear(renderer);

    SDL_PumpEvents();

    init_screen();        
    
    uint8_t running = 1;
    uint8_t mouse_down = 0;
    int32_t mouse_x = 0;
    int32_t mouse_y = 0;
    uint32_t ticker = 0;

    uint8_t cooldown = 0;

    while(running) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
                break;
            }
            
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                mouse_x = event.button.x;
                mouse_y = event.button.y;

                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouse_down |= 1;
                }
            }

            if (event.type == SDL_MOUSEBUTTONUP) { 
                mouse_x = event.button.x;
                mouse_y = event.button.y;

                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouse_down = 0; 
                }
            }

            if (event.type == SDL_MOUSEMOTION) { 
                mouse_x = event.button.x;
                mouse_y = event.button.y;
            }
        }

        usleep(10000);

        if (ticker%1000) {
            update();
            refresh(renderer);
            if (mouse_down && cooldown == 0) {
                insert_particle(mouse_x/PARTICLE_SIZE,mouse_y/PARTICLE_SIZE,0xC2,0xB2,0x80,255);
                cooldown = 2;
            }
            ticker = 0;
            if (cooldown)
                cooldown--;
        }

        ticker++;
    }
    
    // Free allocated particles

    for (int32_t r = 0; r < VERTICAL_PARTICLES; r++) {
        for (int32_t c = 0; c < HORIZONTAL_PARTICLES; c++) {
            if (grid[r][c] != nullptr) {
                delete grid[r][c];
            }
        }
    }

    // Clean up resources
    SDL_DestroyWindow(window);
    SDL_Quit();
}

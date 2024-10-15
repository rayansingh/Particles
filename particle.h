// particle.h - Defines related to particle struct
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL2/SDL.h>
#include <stdint.h>

#define PARTICLE_SIZE 5

struct particle {
    uint8_t is;
    SDL_Colour c;
};

#endif // PARTICLE_H

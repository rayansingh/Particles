// particle.h - Defines related to particle struct
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL2/SDL.h>
#include <cstdint>

#define PARTICLE_SIZE 5

class Particle {
public:
    SDL_Colour color;

    Particle();
    Particle(SDL_Colour color);
    Particle(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};


#endif // PARTICLE_H

// particle.h - Defines related to particle struct
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

#define PARTICLE_SIZE 5

typedef enum {
    PARTICLE,
    SAND,
    WATER,
    GRAVEL
} particle_type_t;

class Particle {
public:
    SDL_Colour color;
    float density; // grams/ml
    float angle_of_repose;
    std::string name;

    Particle();
    Particle(SDL_Colour color);
    Particle(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};

class Sand : public Particle {
public:
    Sand();
};

class Water : public Particle {
public:
    Water();
};

class Gravel : public Particle {
public:
    Gravel();
};

SDL_Color add_color_variation(uint8_t randomness, SDL_Color c);
SDL_Color add_color_variation(uint8_t randomness_r, uint8_t randomness_g, uint8_t randomness_b, uint8_t randomness_a, SDL_Color c);

#endif // PARTICLE_H

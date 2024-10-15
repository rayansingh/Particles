// particle.cpp - Functions defined in particle.h
//

#include "particle.h"
#include <algorithm>

SDL_Color add_color_variation(uint8_t randomness, SDL_Color c) {
    return add_color_variation(randomness,randomness,randomness,randomness,c);
}

SDL_Color add_color_variation(uint8_t randomness_r, uint8_t randomness_g, uint8_t randomness_b, uint8_t randomness_a, SDL_Color c) {
    c.r = static_cast<uint8_t>(std::min(std::max(0,(static_cast<int32_t>(c.r) + (rand()%randomness_r-(randomness_r>>1)))),UINT8_MAX));
    c.g = static_cast<uint8_t>(std::min(std::max(0,(static_cast<int32_t>(c.g) + (rand()%randomness_g-(randomness_g>>1)))),UINT8_MAX));
    c.b = static_cast<uint8_t>(std::min(std::max(0,(static_cast<int32_t>(c.b) + (rand()%randomness_b-(randomness_b>>1)))),UINT8_MAX));
    c.a = static_cast<uint8_t>(std::min(std::max(0,(static_cast<int32_t>(c.a) + (rand()%randomness_a-(randomness_a>>1)))),UINT8_MAX));
    
    return c;
}

Particle::Particle() {
    this->angle_of_repose = 45.0;
    this->color = (SDL_Color){255,255,255,255};
}

Particle::Particle(SDL_Color color) {
    this->angle_of_repose = 45.0;
    this->color = color;
}

Particle::Particle(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    this->angle_of_repose = 45.0;
    this->color = (SDL_Color){r,g,b,a};
}

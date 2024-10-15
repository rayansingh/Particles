// particle.cpp - Functions defined in particle.h
//

#include "particle.h"

Particle::Particle() {
    this->color = (SDL_Color){255,255,255,255};
}

Particle::Particle(SDL_Color color) {
    this->color = color;
}

Particle::Particle(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    this->color = (SDL_Color){r,g,b,a};
}

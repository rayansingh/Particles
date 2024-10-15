// sand.cpp - Sand class functions
//

#include "particle.h"

#define SAND_COLOR (SDL_Color){0xC2,0xB2,0x80,255}

Sand::Sand() : Particle(add_color_variation(16,SAND_COLOR)) {
    this->name = "sand";
    this->density = 1.52;
    this->angle_of_repose = 35.0;
}

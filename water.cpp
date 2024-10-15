// water.cpp - Water class functions
//

#include "particle.h"

#define WATER_COLOR (SDL_Color){0x33,0xCC,0xFF,127}

Water::Water() : Particle(add_color_variation(8,8,0,10,WATER_COLOR)) {
    this->name = "water";
    this->density = 1;
    this->angle_of_repose = 35.0;
}

// gravel.cpp - Gravel class functions
//

#include "particle.h"

#define GRAVEL_COLOR (SDL_Color){0x4A,0x44,0x4B,255}

Gravel::Gravel() : Particle(add_color_variation(16,GRAVEL_COLOR)) {
    this->name = "gravel";
    this->density = 1.5;
    this->angle_of_repose = 42.0;
}

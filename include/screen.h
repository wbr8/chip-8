#pragma once
#include <SDL2/SDL.h>

typedef struct Screen {
    SDL_Rect pixels[32][64];
} Screen;

void draw_pixel(SDL_Surface* win_surface, int x, int y);
void draw_screen(SDL_Surface* win_surface, SDL_Rect** pixel_array, int height, int width);
void clear_screen(SDL_Surface* win_surface, SDL_Rect** pixel_array, int height, int width);

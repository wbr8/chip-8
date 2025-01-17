#pragma once
#include <SDL2/SDL.h>


// 64 x 32 screen 
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 640
#define PIXEL_WIDTH 20

typedef struct Screen {
    SDL_Rect pixels[32][64];    // y then x
    int pixel_colour[32][64];
} Screen;

void draw_pixel(SDL_Surface* win_surface, int x, int y, int state);
void draw_screen(SDL_Surface* win_surface, SDL_Rect pixel_array[][64], int pixel_colour[][64], int height, int width);
void clear_screen(Screen* screen);
void draw_grid(SDL_Surface* win_surface);

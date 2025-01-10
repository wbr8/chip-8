#include "screen.h"

void draw_screen(SDL_Surface* win_surface, SDL_Rect pixel_array[][64], int pixel_colour[][64], int height, int width) {
    for (int y = 0; y < 32; y++) {
        for (int x = 0; x < 64; x++) {
            int state = pixel_colour[y][x];
            if (state == 1){
                SDL_FillRect(win_surface, &pixel_array[y][x], SDL_MapRGB( (win_surface->format) , 255, 255, 255));      // white pixel (on)
            } else if (state == 0) {
                SDL_FillRect(win_surface, &pixel_array[y][x], SDL_MapRGB( (win_surface->format) , 0, 0, 0));            // black pixel (off)
            }
        }
    }
}

void clear_screen(SDL_Surface* win_surface, SDL_Rect** pixel_array, int height, int width) {

}

void draw_pixel(SDL_Surface* win_surface, int x, int y, int state) {
    SDL_Rect pixel = (SDL_Rect) {x * 20, y * 20, PIXEL_WIDTH, PIXEL_WIDTH};
    if (state == 1){
        SDL_FillRect(win_surface, &pixel, SDL_MapRGB( (win_surface->format) , 255, 255, 255));      // white pixel (on)
    } else if (state == 0) {
        SDL_FillRect(win_surface, &pixel, SDL_MapRGB( (win_surface->format) , 0, 0, 0));            // black pixel (off)
    }   
}

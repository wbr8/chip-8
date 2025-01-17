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

void clear_screen(Screen* screen) {
    for (int y = 0;  y < 32; y++) {
        for (int x = 0; x < 64; x++) {
            screen->pixels[y][x] = (SDL_Rect) {(x) * 20, (y) * 20, PIXEL_WIDTH, PIXEL_WIDTH};
            screen->pixel_colour[y][x] = 0;
        }
    }
}

void draw_pixel(SDL_Surface* win_surface, int x, int y, int state) {
    SDL_Rect pixel = (SDL_Rect) {x * 20, y * 20, PIXEL_WIDTH, PIXEL_WIDTH};
    if (state == 1){
        SDL_FillRect(win_surface, &pixel, SDL_MapRGB( (win_surface->format) , 255, 255, 255));      // white pixel (on)
    } else if (state == 0) {
        SDL_FillRect(win_surface, &pixel, SDL_MapRGB( (win_surface->format) , 0, 0, 0));            // black pixel (off)
    }   
}

void draw_grid(SDL_Surface* win_surface) {
    SDL_Rect vertical_grid_line = (SDL_Rect) {0, 0, 2, WINDOW_HEIGHT};
    SDL_Rect horizontal_grid_line = (SDL_Rect) {0, 0, WINDOW_WIDTH, 2};

    SDL_Rect grid[98];
    for (int i = 0; i <= 64; i++) {
        grid[i] = vertical_grid_line;
        vertical_grid_line.x = vertical_grid_line.x + 20;
    }
    for (int i=65; i <= 96; i++) {
        grid[i] = horizontal_grid_line;
        horizontal_grid_line.y = horizontal_grid_line.y + 20;
    }
    horizontal_grid_line.w = horizontal_grid_line.w + 2;    // added 2 to fill in small unfilled square at bottom right
    grid[97] = horizontal_grid_line;

    Uint32 grey = SDL_MapRGB( (win_surface->format), 32, 32, 32);
    SDL_FillRects(win_surface, grid, 98, grey);
}

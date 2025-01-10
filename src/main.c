#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "chip8.h"
#include "screen.h"

void draw_grid(SDL_Surface* win_surface);

int main(int argc, char** argv) {
    SDL_Window* window = NULL;
    SDL_Surface* win_surface = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH + 2, WINDOW_HEIGHT + 2, SDL_WINDOW_SHOWN);   // added 2 to allow space for grid
    SDL_SetWindowResizable(window, SDL_FALSE);
    win_surface = SDL_GetWindowSurface(window);

    // draw_pixel(win_surface, 0, 0, 1);
    // draw_pixel(win_surface, 63, 31, 1);
    // draw_grid(win_surface);

    SDL_UpdateWindowSurface(window);

    CPU cpu;
    Screen screen;
    memset(&screen, 0, sizeof(screen));

    emu_init(&cpu);
    dump_cpu_state(&cpu);
    emu_tick(&cpu);
    dump_cpu_state(&cpu);

    screen.pixels[0][0] = (SDL_Rect) {(0) * 20, (0) * 20, PIXEL_WIDTH, PIXEL_WIDTH};
    screen.pixel_colour[0][0] = 1;
    draw_screen(win_surface, screen.pixels, screen.pixel_colour, WINDOW_HEIGHT, WINDOW_WIDTH);
    draw_grid(win_surface);

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
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

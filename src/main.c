#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "chip8.h"
#include "screen.h"

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

    // init cpu and screen structs, always passed in separately and not as one struct
    CPU cpu;
    Screen screen;
    memset(&screen, 0, sizeof(screen));     // emu init takes care of cpu memset, so i still need to do it directly here
    emu_init(&cpu);

    // dump_cpu_state(&cpu);
    // emu_tick(&cpu);
    // dump_cpu_state(&cpu);

    int x = 0;
    int y = 0;
    screen.pixels[y][x] = (SDL_Rect) {(x) * 20, (y) * 20, PIXEL_WIDTH, PIXEL_WIDTH};
    screen.pixel_colour[y][x] = 1;
    draw_screen(win_surface, screen.pixels, screen.pixel_colour, WINDOW_HEIGHT, WINDOW_WIDTH);
    draw_grid(win_surface);
    SDL_Delay(100);
    SDL_Delay(2000);

    x = 1;
    y = 1;
    screen.pixels[y][x] = (SDL_Rect) {(x) * 20, (y) * 20, PIXEL_WIDTH, PIXEL_WIDTH};
    screen.pixel_colour[y][x] = 1;
    draw_screen(win_surface, screen.pixels, screen.pixel_colour, WINDOW_HEIGHT, WINDOW_WIDTH);
    draw_grid(win_surface);
    SDL_Delay(100);
    SDL_Delay(2000);

    clear_screen(&screen);

    // emu_tick(&cpu, &screen);
    // draw_screen(win_surface, screen.pixels, screen.pixel_colour, WINDOW_HEIGHT, WINDOW_WIDTH);
    draw_grid(win_surface);
    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

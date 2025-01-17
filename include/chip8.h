#pragma once
#include <stdint.h>

#include "screen.h"

typedef struct CPU {
    uint8_t memory[4096];   // 4K of memory
    uint16_t pc;            // program counter
    uint16_t I;             // index register   
    uint8_t V[16];          // general purpose registers (V0-VF)
    uint8_t delay_timer;    // countdown timer for delays
    uint8_t sound_timer;    // countdown timer for sound
} CPU;

void emu_init(CPU* cpu);
void emu_load_program(CPU* cpu, FILE* file);
void emu_tick(CPU* cpu, Screen* screen);
void dump_cpu_state(CPU* cpu);

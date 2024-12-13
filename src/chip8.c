#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "chip8.h"

void load_font_to_ram(CPU* cpu);
void dump_ram(CPU* cpu);

void emu_init(CPU* cpu) {
    memset(cpu, 0, sizeof(CPU));
    load_font_to_ram(cpu);
    cpu->pc = 0x200;            // move PC to start of program
    dump_ram(cpu);
}

void dump_cpu_state(CPU* cpu) {
    printf("PC: 0x%04X, I: 0x%04X\n", cpu->pc, cpu->I);
    printf("Registers: ");
    for (int i = 0; i < 16; i++) {
        printf("V[%d]: 0x%02X ", i, cpu->V[i]);
    }
    printf("\n");
}

void dump_ram(CPU* cpu) {
    int counter = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            printf("0x%x ", cpu->memory[counter++]);
        }
        putchar('\n');
    }
}

void emu_tick(CPU* cpu) {
    // TODO: implement an actual CPU cycle
    int opcode = cpu->memory[cpu->pc] << 8 | cpu->memory[cpu->pc + 1];
    cpu->pc = cpu->pc + 2;


}

void load_font_to_ram(CPU* cpu) {
    uint8_t font[16][5] = {
        {0xF0, 0x90, 0x90, 0x90, 0xF0},     // 0
        {0x20, 0x60, 0x20, 0x20, 0x70},     // 1
        {0xF0, 0x10, 0xF0, 0x80, 0xF0},     // 2
        {0xF0, 0x10, 0xF0, 0x10, 0xF0},     // 3
        {0x90, 0x90, 0xF0, 0x10, 0x10},     // 4
        {0xF0, 0x80, 0xF0, 0x10, 0xF0},     // 5
        {0xF0, 0x80, 0xF0, 0x90, 0xF0},     // 6
        {0xF0, 0x10, 0x20, 0x40, 0x40},     // 7
        {0xF0, 0x90, 0xF0, 0x90, 0xF0},     // 8
        {0xF0, 0x90, 0xF0, 0x10, 0xF0},     // 9
        {0xF0, 0x90, 0xF0, 0x90, 0x90},     // A
        {0xE0, 0x90, 0xE0, 0x90, 0xE0},     // B
        {0xF0, 0x80, 0x80, 0x80, 0xF0},     // C
        {0xE0, 0x90, 0x90, 0x90, 0xE0},     // D
        {0xF0, 0x80, 0xF0, 0x80, 0xF0},     // E
        {0xF0, 0x80, 0xF0, 0x80, 0x80}      // F
    };

    int counter = 0x50;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            cpu->memory[counter++] = font[i][j];
        }
    }
}

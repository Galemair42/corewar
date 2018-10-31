#include "corewar.h"

void        cw_put_four_octet(unsigned int index, unsigned int four_octet)
{
    arena.memory[index] = four_octet >> 24;
    arena.memory[index + 1] = (four_octet >> 16) & 0xFFFFFF00;
    arena.memory[index + 2] = (four_octet >> 8) & 0xFFFFFF00;
    arena.memory[index + 3] = four_octet & 0xFFFFFF00;
}
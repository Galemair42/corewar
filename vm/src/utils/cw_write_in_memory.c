#include "corewar.h"

void          cw_put_four_octet(unsigned int index, unsigned int four_octet)
{
    arena.memory[index] = four_octet >> 24;
    arena.memory[index + 1] = (four_octet >> 16) & 0xFF;
    arena.memory[index + 2] = (four_octet >> 8) & 0xFF;
    arena.memory[index + 3] = four_octet & 0xFF;
}

unsigned int    cw_get_four_octet(unsigned int index)
{
    unsigned int result;
    
    result = arena.memory[index] << 24;
    result += arena.memory[MEM_MASK(index + 1)] << 16;
    result += arena.memory[MEM_MASK(index + 2)] << 8;
    result += arena.memory[MEM_MASK(index + 3)];
    return (result);
}
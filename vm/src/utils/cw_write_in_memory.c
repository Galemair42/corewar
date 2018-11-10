#include "corewar.h"

void        cw_put_four_octet_visu(unsigned int index,
        unsigned int four_octet, WINDOW *win)
{
    wmove(win, 0, 0);
    refresh();
    arena.memory[index] = four_octet >> 24;
    arena.memory[MEM_MASK(index + 1)] = (four_octet >> 16) & 0xFF;
    arena.memory[MEM_MASK(index + 2)] = (four_octet >> 8) & 0xFF;
    arena.memory[MEM_MASK(index + 3)] = four_octet & 0xFF;
    mvwprintw(win, (index / 64) + 1, ((index % 64) * 3) + 3, "%.2X", arena.memory[index]);
    mvwprintw(win, ((MEM_MASK(index + 1)) / 64) + 1, (((MEM_MASK(index + 1)) % 64) * 3) + 3,
    "%.2X", arena.memory[MEM_MASK(index + 1)]);
    mvwprintw(win, ((MEM_MASK(index + 2)) / 64) + 1, (((MEM_MASK(index + 2)) % 64) * 3) + 3,
    "%.2X", arena.memory[MEM_MASK(index + 2)]);
    mvwprintw(win, ((MEM_MASK(index + 3)) / 64) + 1, (((MEM_MASK(index + 3)) % 64) * 3) + 3,
    "%.2X", arena.memory[MEM_MASK(index + 3)]);
}

void          cw_put_four_octet(unsigned int index, unsigned int four_octet)
{
    arena.memory[index] = four_octet >> 24;
    arena.memory[MEM_MASK(index + 1)] = (four_octet >> 16) & 0xFF;
    arena.memory[MEM_MASK(index + 2)] = (four_octet >> 8) & 0xFF;
    arena.memory[MEM_MASK(index + 3)] = four_octet & 0xFF;
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
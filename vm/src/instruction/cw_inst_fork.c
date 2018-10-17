#include "corewar.h"

void    cw_inst_fork(t_processus *process)
{
    int             location;
    unsigned int    pc;
    unsigned char   *memory;

    pc = process->pc;
    memory = arena.memory;
    pc++;
    pc &= ~(~((unsigned)0) << 12); 
    printf("pc :%u\n", pc);
    printf("test :%u\n", (~0) << 12);
    exit(5);
    location = memory[pc] << 8;
    pc++;
    pc &= ~((~0) << 12));
//
    location = memory[pc];
}
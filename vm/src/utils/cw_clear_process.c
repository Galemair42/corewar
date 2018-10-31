#include "corewar.h"

void        cw_clear_process(t_processus *process)
{
    process->opcode = 0;
    process->ocp = 0;
    ft_bzero(process->reg, sizeof(unsigned int) * REG_NUMBER);
    ft_bzero(process->params, sizeof(unsigned int) * 3);
}
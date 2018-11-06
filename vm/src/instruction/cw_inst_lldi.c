#include "corewar.h"

void    cw_inst_lldi(t_processus *process)
{
    int landing;
    int ret;

    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    landing = MEM_MASK(process->params[0] + process->params[1]);
    process->reg[process->params[2]] = arena.memory[landing];
    process->pc = (process->pc + ret) & 0xFFF; // c'est ok ca ?
    cw_reset_process(process);
}
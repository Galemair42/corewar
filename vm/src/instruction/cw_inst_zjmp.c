#include "corewar.h"

cw_inst_zjmp(t_processus *process)
{
    int     ret;

    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process();
        return ;
    }
    if (process->carry == 1)
    {
        process->pc = apply_IDX_MOD(process->pc,
        (process->pc + process->params[0]) % MEM_SIZE)
    }
    process->pc = (process->pc + ret) & 0xFFF; // c'est ok ca ?
}
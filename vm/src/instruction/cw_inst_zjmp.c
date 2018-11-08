#include "corewar.h"

void    cw_inst_zjmp(t_processus *process)
{
    int     ret;

    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    if (process->carry == 1)
    {
        process->pc = apply_IDX_MOD(process->pc,
        MEM_MASK(process->pc + process->params[0]));
    }
    else
        process->pc = MEM_MASK(process->pc + 1);
    cw_reset_process(process);
}

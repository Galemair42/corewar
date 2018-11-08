#include "corewar.h"

void cw_inst_st(t_processus *process)
{
    int     param_2;
    int     ret;
    int     landing;
    
    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    if (((process->ocp >> 4) & 3) == IND_CODE)
    {
        landing = apply_IDX_MOD(process->pc, process->pc + process->params[1]);
        landing = MEM_MASK(landing);
        cw_put_four_octet(landing, process->reg[process->params[0]]);
    }
    else
        process->reg[process->params[1]] = process->reg[process->params[0]];
    process->pc = MEM_MASK(ret);
    cw_reset_process(process);
}
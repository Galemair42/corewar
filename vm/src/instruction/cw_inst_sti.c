#include "corewar.h"

/*
**      j'ai la taille d'une instru ??
*/

void    cw_inst_sti(t_processus *process)
{
    int     param_2;
    int     param_3;
    int     landing;
    int     ret;

    landing = 0;
    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    if (((process->ocp >> 4) & 3) == IND_CODE)
        landing += process->params[1];
    else if (((process->ocp >> 4) & 3) == REG_CODE)
        landing += process->reg[process->params[1]];
    if ((((process->ocp >> 2) & 3) == IND_CODE))
        landing += process->params[2]; 
    else if (((process->ocp >> 4) & 3) == REG_CODE)
        landing += process->reg[process->params[2]];
    landing = MEM_MASK(landing);
    apply_IDX_MOD(process->pc, MEM_MASK(landing));
    cw_put_four_octet(landing, process->reg[process->params[0]]);
    process->pc = ret; 
    cw_reset_process(process);
}
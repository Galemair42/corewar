#include "corewar.h"

/*
**      j'ai la taille d'une instru ??
*/

void    cw_inst_sti(t_processus *process)
{
    int     reg_1;
    int     param_2;
    int     param_3;
    int     landing;
    int     ret;

    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    reg_1 = process->reg[process->params[0]];
    if (((process->ocp >> 4) & ~3) == 1)
        param_2 = process->reg[process->params[1]];
    else
        param_2 = process->params[1];
    if (((process->ocp >> 6) & ~3) == 1)
        param_3 = process->reg[process->params[2]];
    else
        param_3 = process->params[2];
    landing = apply_IDX_MOD(process->pc,
    (process->pc + param_2 + param_3) % MEM_SIZE);
    cw_put_four_octet(landing, reg_1);
    process->pc = (process->pc + ret) & 0xFFF;
    cw_reset_process(process);
}
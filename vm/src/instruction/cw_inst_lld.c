#include "corewar.h"

void        cw_inst_lld(t_processus *process)
{
    int     dir_1;
    int     reg_2;
    int     landing;

    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process();
        return ;
    }
    // ici je ne dois pas faire une verif sur la taille de ret ??

    if ((process->ocp >> 2) & 3 == DIR_CODE)
    {
        process->reg[process->params[1]] = process->params[0];
    }
    else if ((process->ocp >> 2) & 3 == IND_CODE)
    {
        landing = apply_IDX_MOD(process->pc, process->pc + process->params[0]);
        process->reg[process->params[1]] = cw_get_four_octet();
    }
    landing = apply_IDX_MOD(process->pc, process->pc + );
    process->reg[process->params[1]] = process->params[0];
    process->pc = (process->pc + ret) & 0xFFF; // c'est ok ca ?
}
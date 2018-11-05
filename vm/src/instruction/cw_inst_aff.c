#include "corewar.h"

void    cw_inst_aff(t_processus *process)
{
    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process();
        return ;
    }
    write(1, process->reg[process->params[0]] % 256, 1);
}
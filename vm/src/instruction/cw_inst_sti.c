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
    {
        landing += process->params[1];
    }
    
    cw_reset_process(process);
}

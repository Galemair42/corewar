#include "corewar.h"

void    cw_inst_lldi(t_processus *process)
{
    unsigned int    landing;
    unsigned int    ret;

    if ((ret = get_params(process, 1)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    landing = cw_get_one_params(process, 1, true);
    if ((((process->ocp >> 4) & 3) == DIR_CODE))
        landing += process->params[1];
    else if ((((process->ocp >> 4) & 3) == REG_CODE))
        landing += process->reg[process->params[1]];
    landing = MEM_MASK(process->pc + landing);
    if (arena.visu_fight)
    {
        ;//cw_put_four_octet_visu(landing, process->reg[process->params[0]], arena.mem_color[process->pc]);
        cw_visu_incr_process(process, ret);
    }
    //else
        process->reg[process->params[2]] = cw_calculate_value_on_ram(landing, 4);
    process->pc = ret;
    cw_reset_process(process); 
}

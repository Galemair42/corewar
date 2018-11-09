#include "corewar.h"

void    cw_inst_lldi(t_processus *process)
{
    int landing;
    int ret;

    if ((ret = get_params(process, 1)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    landing = MEM_MASK(process->params[0] + process->params[1] + process->pc);
    process->reg[process->params[2]] = cw_calculate_value_on_ram(landing, 4);
    if (arena.visu_fight)
        cw_visu_incr_process(process, ret);
    process->pc = ret;
    cw_reset_process(process);
}

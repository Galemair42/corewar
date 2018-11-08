#include "corewar.h"

void    cw_inst_ldi(t_processus *process)
{
    int landing;
    int ret;

    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    landing = process->params[0] + process->params[1] + process->pc;
    landing = apply_IDX_MOD(process->pc, MEM_MASK(landing));
    process->reg[process->params[2]] = cw_calculate_value_on_ram(landing, 4);
    cw_reset_process(process);
    process->pc = ret;
}
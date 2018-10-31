#include "corewar.h"

void    cw_inst_ldi(t_processus *process)
{
    int landing;
    int result;
    
    landing = process->params[0] + process->params[1];
    result = apply_IDX_MOD(process->pc, (process->pc + landing));
    // chepa
}
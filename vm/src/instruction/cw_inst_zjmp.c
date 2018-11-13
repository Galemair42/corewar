#include "corewar.h"

void    cw_inst_zjmp(t_processus *process)
{
	unsigned int	param;
    int             new_pc;

	param = cw_calculate_value_on_ram(process->pc + 1, 2);
    if (process->carry == 1)
    {
        new_pc = apply_IDX_MOD(process->pc, MEM_MASK(process->pc + param)); 
        if (arena.visu_fight) 
            cw_visu_incr_process(process, new_pc);
        process->pc = new_pc;
    }
    else
    {
        if (arena.visu_fight) 
            cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
        process->pc = MEM_MASK(process->pc + 1);
    }
    cw_reset_process(process);
}

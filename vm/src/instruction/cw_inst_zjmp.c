#include "corewar.h"

void    cw_inst_zjmp(t_processus *process)
{
	unsigned int	param;

	param = cw_calculate_value_on_ram(process->pc + 1, 4);
    if (process->carry == 1)
    {
        process->pc = apply_IDX_MOD(process->pc,
        MEM_MASK(process->pc + param));
    }
    else
        process->pc = MEM_MASK(process->pc + 1);
    cw_reset_process(process);
}

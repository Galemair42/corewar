#include "corewar.h"

void        cw_clear_process(t_processus *process)
{
    process->opcode = 0;
    process->ocp = 0;
    ft_bzero(process->reg, sizeof(unsigned int) * REG_NUMBER);
    ft_bzero(process->params, sizeof(unsigned int) * 3);
}

void		cw_clear_exec_tab(void)
{
	int i;
	t_processus *to_free;
	t_processus *tmp;

	i = 0;
	while (i < CYCLE_TO_DIE)
	{
		to_free = arena.process_to_exec[i];
		while (to_free)
		{
			tmp = to_free->next;
			free(to_free);
			to_free = tmp;
		}
//		ft_bzero(arena.process_to_exec[i], sizeof(t_processus *));
		i++;
	}
}

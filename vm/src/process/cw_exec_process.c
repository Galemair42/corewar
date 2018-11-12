#include "corewar.h"

static void		cw_init_funtab(void (**ptr)(t_processus *))
{
	ptr[0] = &cw_inst_live;
	ptr[1] = &cw_inst_live;
	ptr[2] = &cw_inst_live;
	ptr[3] = &cw_inst_live;
	ptr[4] = &cw_inst_live;
	ptr[5] = &cw_inst_live;
	ptr[6] = &cw_inst_live;
	ptr[7] = &cw_inst_live;
	ptr[8] = &cw_inst_live;
	ptr[9] = &cw_inst_live;
	ptr[10] = &cw_inst_live;
	ptr[11] = &cw_inst_fork;
	ptr[12] = &cw_inst_live;
	ptr[13] = &cw_inst_live;
	ptr[14] = &cw_inst_live;
	ptr[15] = &cw_inst_live;
}

void				cw_exec_process(t_list *process)
{
	static void (*ptr[16]) (t_processus *);
 
 	if (!*ptr)
		cw_init_funtab(ptr);
    
}

void		cw_reset_process(t_processus *process)
{
	process->ocp = 0;
	process->next = NULL;
	ft_bzero(process->params, sizeof(int) * 4);
}

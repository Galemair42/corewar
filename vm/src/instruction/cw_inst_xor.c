#include "corewar.h"

/*
**      pour l'instant carry = 0 si resultat = 0
**      sinon 1
*/

void        cw_inst_xor(t_processus *process)
{
    int     reg_1;
    int     reg_2;
    int     reg_3;
    int     ret;


    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    reg_1 = process->reg[process->params[0]];
    reg_2 = process->reg[process->params[1]];
    reg_3 = process->params[2];
    if (!(process->reg[reg_3] = reg_1 ^ reg_2))
        process->carry = 1;
    else
        process->carry = 0;
    process->pc = (process->pc + ret) & 0xFFF; // c'est ok ca ?
    cw_reset_process(process);
}
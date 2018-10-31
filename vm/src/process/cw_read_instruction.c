#include "corewar.h"

static t_cw_op_tab    op_tab[17] =
{
	{1, T_DIR, 1, 10, 0},
	{2, (T_DIR | T_REG) | (T_REG << 8), 2, 5, 1},
	{2, T_REG | ((T_IND | T_REG) << 8), 3, 5, 1},
	{3, T_REG | (T_REG << 8) | (T_REG << 16), 4, 10, 1},
	{3, T_REG | (T_REG << 8) | (T_REG << 16), 5, 10, 1},
	{3, (T_REG | T_DIR | T_IND) | ((T_REG | T_IND | T_DIR) << 8) | (T_REG << 16), 6, 6, 1},
	{3, (T_REG | T_IND | T_DIR) | ((T_REG | T_IND | T_DIR) << 8) | (T_REG << 16), 7, 6, 1},
	{3, (T_REG | T_IND | T_DIR) | ((T_REG | T_IND | T_DIR) << 8) | (T_REG << 16), 8, 6, 1},
	{1, T_DIR, 9, 20, 0},
	{3, (T_REG | T_IND | T_DIR) | ((T_REG | T_IND | T_DIR) << 8), 10, 25, 1},
	{3, (T_REG) | ((T_REG | T_DIR | T_IND) << 8) | T_REG, 11, 25, 1},
	{1, T_DIR, 12, 800, 0},
	{2, (T_DIR | T_IND) |  (T_REG << 8), 13, 10, 1},
	{3, (T_REG | T_DIR | T_IND) | ((T_DIR | T_REG) << 8) | T_REG << 16, 14, 50, 1},
	{1, T_DIR, 15, 1000, 0},
	{1, T_REG, 16, 2, 1},
};

static  cw_format_instruction(t_processus *process, short unsigned opcode)
{
    unsigned short ocp;
    unsigned short scope;

    ocp = 0;
    if (op_tab[opcode - 1]->bool_ocp)
    {
        scope = (process->pc + 1) & 4095;
        ocp = arena.memory[scope];
    }
    else
    {

    }
}

void    cw_read_instruction (t_processus *process) {
    short unsigned int  opcode;
    short unsigned int  new_pc;
    unsigned char       *arena;

    //arena = arena.memory;
    opcode = arena[process->pc];
    if (opcode > 0 && opcode <= 16)
    {
        cw_read_instru();// voir ca avec gautier mais a priori c'est lui qui va implem ca
    }
    else
    {
        new_pc = process->pc;
        new_pc &= 4095;
    }
}
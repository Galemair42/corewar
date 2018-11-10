#include "corewar.h"

void        cw_display_champ_on_ram(t_champion *champ, WINDOW *win, unsigned int pc)
{
    int     i;

    i = 0;
    wattron(win, WA_STANDOUT);
    mvwprintw(win, (pc / 64) + 1, ((pc % 64) * 3) + 3, "%.2X", arena.memory[pc]);
    wattroff(win, WA_STANDOUT);
    mvwprintw(win, (pc / 64) + 1, ((pc % 64) * 3) + 5, " ", arena.memory[pc]);


    i++;
    pc++;
    while (i < champ->header.prog_size)
    {
        mvwprintw(win, (pc / 64) + 1, ((pc % 64) * 3) + 3, "%.2X ", arena.memory[pc]);
        pc++;
        i++;
        
    }
    wrefresh(win);
}

void        cw_visu_incr_process(t_processus *process, int next_pc)
{
    int     cur_pc;

   // wmove(process->win, 0, 0);
    //refresh();
    //bon jenleve ce truc mais si jamais ya un beug du type 
    ///ca affichage n'importequoi a des endroits completement illogique faut remettre ca
    
    //mvwprintw(process->win, 25, 10, "pc : %d, next pc : %d", process->pc, next_pc);
    //wrefresh(process->win);

    cur_pc = process->pc;
    mvwprintw(process->win, (cur_pc / 64) + 1, ((cur_pc % 64) * 3) + 3,
    "%.2X", arena.memory[cur_pc]);
    wattron(process->win, WA_STANDOUT);
    mvwprintw(process->win, (next_pc / 64) + 1, ((next_pc % 64) * 3) + 3,
    "%.2X", arena.memory[next_pc]);
    wattroff(process->win, WA_STANDOUT);
    wrefresh(process->win);
}
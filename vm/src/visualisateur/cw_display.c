#include "corewar.h"

static int      cw_champ_color(void)
{
    static int      color;

    color++;
    if (color == 1)
        return (CW_GREEN);
    else if (color == 2)
        return (CW_BLUE);
    else if (color == 3)
        return (CW_RED);
    else
        return (CW_CYAN);
}

void            cw_highlight(unsigned int index)
{
    wattron(arena.visu_fight, COLOR_PAIR(arena.mem_color[index]));
    wattron(arena.visu_fight, A_STANDOUT);
    mvwprintw(arena.visu_fight, (index / 64) + 1, ((index % 64) * 3) + 3, "%.2X ", arena.memory[index]); 
    wattroff(arena.visu_fight, A_STANDOUT);
    wattroff(arena.visu_fight, COLOR_PAIR(arena.mem_color[index]));
}

void            cw_display_champ_on_ram(t_champion *champ, t_processus *process)
{
    int             i;
    unsigned int    pc;
    int             color_pair;
    static int      stop;
    stop++;

    color_pair = cw_champ_color();
    pc = process->pc;
    i = 0;
    wattron(arena.visu_fight, COLOR_PAIR(color_pair));
    wattron(arena.visu_fight, WA_STANDOUT);
    mvwprintw(arena.visu_fight, (pc / 64) + 1, ((pc % 64) * 3) + 3, "%.2X", arena.memory[pc]);
    wattroff(arena.visu_fight, WA_STANDOUT);

    ft_memset(&arena.mem_color[pc], color_pair, champ->header.prog_size);
    i++;
    pc++;

    while (i < champ->header.prog_size)
    {
        mvwprintw(arena.visu_fight, (pc / 64) + 1, ((pc % 64) * 3) + 3, "%.2X ", arena.memory[pc]);
        pc++;
        i++;
    }
    wrefresh(arena.visu_fight);
    wattroff(arena.visu_fight, COLOR_PAIR(color_pair));
}

void        cw_visu_incr_process(t_processus *process, int next_pc)
{
    int     cur_pc;

    cur_pc = process->pc;
   // wmove(process->win, 0, 0);
    //refresh();
    //bon jenleve ce truc mais si jamais ya un beug du type 
    ///ca affichage n'importequoi a des endroits completement illogique faut remettre ca
    
    // desouligner de la bonne couleur

    wattron(arena.visu_fight, COLOR_PAIR(arena.mem_color[cur_pc]));
    mvwprintw(arena.visu_fight, (cur_pc / 64) + 1, ((cur_pc % 64) * 3) + 3,
    "%.2X", arena.memory[cur_pc]);
    wattroff(arena.visu_fight, COLOR_PAIR(arena.mem_color[cur_pc]));

    wattron(arena.visu_fight, COLOR_PAIR(arena.mem_color[next_pc]));
    wattron(arena.visu_fight, WA_STANDOUT);
    mvwprintw(arena.visu_fight, (next_pc / 64) + 1, ((next_pc % 64) * 3) + 3,
    "%.2X", arena.memory[next_pc]);
    wattroff(arena.visu_fight, WA_STANDOUT);
    wattroff(arena.visu_fight, COLOR_PAIR(arena.mem_color[next_pc]));

    wrefresh(arena.visu_fight);
}
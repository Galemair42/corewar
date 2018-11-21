FLAGS = -Wall -Wextra -Werror
NAME = corewar
LIB = ../libft/libft.a ../libft/ft_printf/libftprintf.a
OBJ_DIR = obj/
SRC_DIR = src/:src/champion/:src/instruction/:src/parsing/:src/process/:src/utils/:src/visualisateur
vpath %.c $(SRC_DIR)

INC = \
		inc/ 

SRC = \
		src/champion/cw_add_champ.c	\
		src/champion/cw_manip_champ.c	\
		src/champion/cw_put_champ_mem.c	\
		src/champion/cw_read_champ.c	\
		src/cw_core_vm.c	\
		src/cw_init.c	\
		src/cw_main.c	\
		src/instruction/cw_get_instructions_params.c	\
		src/instruction/cw_inst_add.c	\
		src/instruction/cw_inst_aff.c	\
		src/instruction/cw_inst_and.c	\
		src/instruction/cw_inst_fork.c	\
		src/instruction/cw_inst_ld.c	\
		src/instruction/cw_inst_ldi.c	\
		src/instruction/cw_inst_lfork.c	\
		src/instruction/cw_inst_live.c	\
		src/instruction/cw_inst_lld.c	\
		src/instruction/cw_inst_lldi.c	\
		src/instruction/cw_inst_or.c	\
		src/instruction/cw_inst_st.c	\
		src/instruction/cw_inst_sti.c	\
		src/instruction/cw_inst_sub.c	\
		src/instruction/cw_inst_xor.c	\
		src/instruction/cw_inst_zjmp.c	\
		src/instruction/cw_instructions_utils.c	\
		src/parsing/cw_parse_varg.c	\
		src/process/cw_exec_process.c	\
		src/process/cw_verif_processes.c	\
		src/process_lst_utils.c	\
		src/utils/cw_clear_process.c	\
		src/utils/cw_list.c	\
		src/utils/cw_write_in_memory.c	\
		src/utils.c	\
		src/visualisateur/cw_core_visu.c	\
		src/visualisateur/cw_display.c	\
		src/visualisateur/cw_init_visu.c	\
		src/visualisateur/cw_keypad.c	\
		src/visualisateur/cw_process_visu.c	\
		src/visualisateur/cw_score.c		\
		src/utils/cw_exit_properly.c		\
		src/utils/cw_core_vm_helper.c		\
		src/utils/cw_usage.c				\

OBJS = $(SRC:.c=.o)
OBJS := $(notdir $(OBJS))
OBJS := $(addprefix $(OBJ_DIR), $(OBJS))


T = $(words $(SRC))
N = x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\r[\033[33m`expr $C '*' 100 / $T`%\033[0m] \
	   Compiling \033[35m$(NAME)\033[0m...\c"

all : obj_dir $(NAME)
	@gcc $(FLAGS) -o $(NAME) $(addprefix -I , $(INC)) $(OBJS) $(LIB) -lncurses
	@echo "\r[\033[32m100%\033[0m] \033[35m$(NAME)\033[0m is ready!   "

$(NAME): $(OBJS)

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< $(addprefix -I , $(INC))
	@$(ECHO)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

obj_dir:
	@mkdir -p obj

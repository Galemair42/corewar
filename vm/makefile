FT_PATH=../libft/
FLAGS = -ggdb -g
NAME = corewar
FT_NAME = $(FT_PATH)libft.a
LIB = $(FT_PATH)libft.a
OBJ_DIR = obj/
SRC_DIR = src/:src/champion/:src/instruction/:src/parsing/:src/process/:src/utils/:src/visualisateur
vpath %.c $(SRC_DIR)

INC = \
		inc/ \
		$(FT_PATH)includes/

SRC = \
		src/champion/cw_add_champ.c	\
		src/champion/cw_manip_champ.c	\
		src/champion/cw_put_champ_mem.c	\
		src/champion/cw_read_champ.c	\
		src/cw_core_vm.c	\
		src/cw_init.c	\
		src/cw_main.c	\
		src/debug.c	\
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
		src/visualisateur/cw_score.c		\
		src/utils/cw_exit_properly.c		\
		src/utils/cw_core_vm_helper.c		\

OBJS = $(SRC:.c=.o)
OBJS := $(notdir $(OBJS))
OBJS := $(addprefix $(OBJ_DIR), $(OBJS))

FT_SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstappend.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_nbdigits.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcarac.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoinfree.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strnchr.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \

FT_SRC := $(addprefix $(FT_PATH), $(FT_SRC))
FT_OBJS := $(FT_SRC:.c=.o)

all : obj_dir $(NAME)
	@gcc $(FLAGS) -o $(NAME) $(addprefix -I , $(INC)) $(OBJS) $(LIB) -lncurses
	@echo "COREWAR COMPILED\n"

$(NAME): $(OBJS) $(FT_OBJS)

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< $(addprefix -I , $(INC))
	@printf ' 🖥  '

$(FT_PATH)%.o: $(FT_PATH)%.c
	@make -C $(FT_PATH)

clean: 
	@make clean -C $(FT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(FT_PATH)
	@rm -f $(NAME)

re: fclean all

obj_dir:
	@mkdir -p obj

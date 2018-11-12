## all the FT_... variables are declared in the parent makefile
## $(info $$var is [${var}])

SRC=$(wildcard *.c)
NAME=libft.a
OBJS=$(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\nLIBFT COMPILED\n"

$(FT_PATH)%.o : $(FT_PATH)%.c
	@printf " 📱 "
	@gcc -o $@ -c $< $(FLAGS) -I includes/

clean:
	@rm -f $(FT_PATH)$(OBJS)

fclean: clean
	@rm -f $(FT_PATH)$(NAME)

re: fclean all

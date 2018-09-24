SRC=$(wildcard *.c)
FLAGS=-Wall -Wextra -Werror
NAME=libft.a
OBJS=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n\033[32mLIBFT COMPILED\n"

%.o : %.c
	@printf "|"
	@gcc -o $@ -c $< $(FLAGS) -I includes/

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re:fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/11/07 16:53:53 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

all:
	@$(MAKE) -C libft/
	@$(MAKE) -C asm/
#	@$(MAKE) -C corewar/

clean:
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C asm/ clean
#	@$(MAKE) -C corewar/ clean

fclean:
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C asm/ fclean
#	@$(MAKE) -C corewar/ fclean

re: fclean all

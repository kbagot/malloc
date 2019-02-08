# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 17:47:06 by kbagot            #+#    #+#              #
#    Updated: 2017/04/07 12:50:37 by kbagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = malloc
FLAGS =  #-fsanitize=address -O0 -g3
I_FILES = main.c
O_FILES = $(I_FILES:.c=.o)
C_FILES = $(addprefix src/, $(I_FILES))
LIBFT = -L libft/ -lft

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(C_FILES) include/malloc.h Makefile
	@echo "\033[0;35mCompile $(NAME)"
	@make -C libft/
	@gcc -c $(FLAGS) $(C_FILES)
	@gcc -o $(NAME) -I include/malloc.h $(FLAGS) $(O_FILES) $(LIBFT)
clean:
	@echo "\033[0;35mDelete $(NAME) object files"
	@rm -rf $(O_FILES)
	@make -C libft/ clean
fclean: clean
	@echo "\033[0;35mDelete $(NAME)"
	@rm -rf $(NAME)
	@make -C libft/ fclean
re: fclean all

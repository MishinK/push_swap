# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 18:14:47 by ashea             #+#    #+#              #
#    Updated: 2021/06/08 18:14:50 by ashea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
HEADER1 = checker_src/
HEADER2 = push_swap_src/
DIRSRC1 = checker_src/
DIRSRC2 = push_swap_src/
SRC1 = 	checker_main.c\
		checker_command.c\
		checker_get_next_line_utils.c\
		checker_get_next_line.c\
		checker_run_action.c\
		checker_stack_init.c\
		checker_stack_ptint.c\
		checker_stack_utilities.c\
		checker_utilities.c\
		checker_utilities2.c
SRC2 = 	push_swap_comb.c\
		push_swap_command.c\
		push_swap_find_mid_value.c\
		push_swap_long_sort.c\
		push_swap_print_result.c\
		push_swap_main.c\
		push_swap_rotate_back.c\
		push_swap_short_sort.c\
		push_swap_sort_three.c\
		push_swap_stack_utilities.c\
		push_swap_swap_elements.c\
		push_swap_utilities.c\
		push_swap_utilities2.c\
		push_swap_utilities3.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	gcc $(FLAGS) -o $(NAME1) $^ 
	echo "\033[5;32m$(NAME1) Successfully \033[0m"

$(NAME2): $(OBJ2)
	gcc $(FLAGS) -o $(NAME2) $^ 
	echo "\033[5;32m$(NAME2) Successfully \033[0m"

%.o: $(DIRSRC1)%.c
	gcc $(FLAGS) -o $@ -c $< -I $(HEADER1)

%.o: $(DIRSRC2)%.c
	gcc $(FLAGS) -o $@ -c $< -I $(HEADER2)

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all
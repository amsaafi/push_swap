# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:54:08 by samsaafi          #+#    #+#              #
#    Updated: 2024/05/13 13:26:37 by samsaafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
COMPILER = cc
CHECKER_BONUS = checker

MANDATORY_SRC = algorithm/algo_utils.c \
				algorithm/push_to_a.c \
				algorithm/push_to_b.c \
				algorithm/sort_4_5.c \
				algorithm/sort_three.c \
				includes/atol.c \
				includes/ft_lstlast.c \
				includes/ft_split.c \
				includes/strlcpy.c \
				operations/push.c \
				operations/rev_rotate.c \
				operations/rotate.c \
				operations/swap.c \
				parsing/check_input.c \
				parsing/free.c \
				parsing/indexing.c \
				parsing/parsing_utils.c \

BONUS_SRC = bonus/gnl/get_next_line_utils.c \
			bonus/gnl/get_next_line.c \
			bonus/includes/atol.c \
			bonus/includes/ft_lstlast.c \
			bonus/includes/ft_split.c \
			bonus/includes/strcmp.c \
			bonus/includes/strlcpy.c \
			bonus/operations/push.c \
			bonus/operations/rev_rotate.c \
			bonus/operations/rotate.c \
			bonus/operations/swap.c \
			bonus/parsing/check_input.c \
			bonus/parsing/free.c \
			bonus/parsing/parsing_utils.c \
			bonus/checker.c \


all: $(NAME)

$(NAME): main.c $(MANDATORY_SRC)
	$(COMPILER) $(CFLAGS) $^ -o $@

bonus : $(CHECKER_BONUS)

$(CHECKER_BONUS): bonus/main_bonus.c $(BONUS_SRC)
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	@rm -f push_swap
	@rm -f checker

fclean : clean

re:    fclean all
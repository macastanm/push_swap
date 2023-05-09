# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macastan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 12:31:46 by macastan          #+#    #+#              #
#    Updated: 2023/03/21 12:33:35 by macastan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker_bonus

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft-pf-gnl/libft.a

SRC = push_swap.c \
		node_manipulation.c \
		frees.c \
		check_content.c \
		sort.c \
		operations.c \
		operations2.c \
		operations3.c \
		finds.c \
		algorithm.c \
		utils.c \
		execution.c

SRC_BONUS = ./bonus/check_bonus.c \
		./bonus/node_manipulation.c \
		./bonus/frees.c \
		./bonus/check_content.c \
		./bonus/operations.c \
		./bonus/operations2.c \
		./bonus/operations3.c \
		./bonus/run_operations.c
		
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft-pf-gnl

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap
	
bonus: $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o checker_bonus

clean:
	$(MAKE) clean -C ./libft-pf-gnl
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft-pf-gnl
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all

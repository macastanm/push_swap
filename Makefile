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
		operations2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft-pf-gnl

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

clean:
	$(MAKE) clean -C ./libft-pf-gnl
	@$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft-pf-gnl
	@$(RM) $(NAME)

re: fclean all

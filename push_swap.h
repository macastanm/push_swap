/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:50:57 by macastan          #+#    #+#             */
/*   Updated: 2023/04/20 12:51:04 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft-pf-gnl/libft.h"

typedef struct s_node
{
	struct s_node	*nx;
	struct s_node	*pv;
	int				ct;
}			t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int				size;
}			t_stack;

// push_swap.c

void	break_arg(char *argv, t_stack *stack_a);
void	print_list(t_stack *stack);
void	multiple_args(int argc, char **argv, t_stack *stack_a);

// node_manipulation.c

t_node	*create_node(int nbr);
void	stack_creat(t_node *new_node, t_stack *stack);
int		check_order(t_stack *stack);

// frees.c

void	free_the_split(char **split);
void	delete_node(t_stack *stack);
void	free_the_list(t_stack *stack);

// check_content

int		check_content(char **argv, int argc);
int		check_dup(char **arr);
int		check_max(char **arr);
int		check_num(char **arr, int i, int j);

// sort

void	sort_2(t_stack *stack_a);

// operations

void	rr(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);

// operations2

void	ss(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);

#endif

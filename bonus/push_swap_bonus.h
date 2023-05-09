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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft-pf-gnl/libft.h"

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

// checker_bonus.c

void	break_arg(char *argv, t_stack *stack_a);
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
int		check_dup2(char **arr);
int		check_max(char **arr);
int		check_num(char **arr, int i, int j);

// operations

void	pa(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);

// operations2

void	pb(t_stack *stack_a, t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);

// operations3

void	rrr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);

// run_operations

void	run_operations(char *line, t_stack *stack_a, t_stack *stack_b);
void	run_operations2(char *line, t_stack *stack_a, t_stack *stack_b);
#endif

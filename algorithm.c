/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:58:05 by macastan          #+#    #+#             */
/*   Updated: 2023/05/02 09:58:21 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_utils(t_utils *utils)
{
	utils->a_data = 0;
	utils->b_data = 0;
	utils->a_rra = 0;
	utils->a_ra = 0;
	utils->b_rrb = 0;
	utils->b_rb = 0;
	utils->rr = 0;
	utils->rrr = 0;
	utils->sum = 0;
}

void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	t_utils	utils;
	int i;

	i = 0;
	init_utils(&utils);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 0)
	{
		utils = find_best_move(stack_a, stack_b, &utils);
		execute_best(&utils, stack_a, stack_b);
	}
	count_moves(find_max(stack_b), stack_b, &utils);
	execute_best(&utils, stack_a, stack_b);
	i = stack_b->size;
	while (i > 0)
	{
		pa(stack_a, stack_b);
		i--;
	}
}

t_utils	find_best_move(t_stack *stack_a, t_stack *stack_b, t_utils *utils)
{
	t_utils best_utils;
	t_stack *copy;
	int i;

	copy = copy_stack(stack_a);
	i = 0;
	count_moves(stack_a->top->ct, stack_a, utils);
	count_moves(find_position(stack_a->top->ct, stack_b), stack_b, utils);
	best_utils = *utils;
	best_utils.sum = sum_moves(utils);
	while (i < copy->size)
	{
		init_utils(utils);
		count_moves(stack_a->top->ct, stack_a, utils);
		count_moves(find_position(stack_a->top->ct, stack_b), stack_b, utils);
		if (check_best(&best_utils, utils) != 1)
			break ;
		copy->top = copy->top->nx;
		i++;
	}
	free(copy);
	return (best_utils);
}

void	count_moves(int n, t_stack *stack, t_utils *utils)
{
	int n_position;
	int middle;

	n_position = find_position(n, stack);
	middle = stack->size / 2;
	if (stack->id == 'a')
		utils->a_data = n;
	else if (stack->id == 'b')
		utils->b_data = n;
	if (n_position == middle || n_position < middle)
	{
		if (stack->id == 'a')
			utils->a_ra = n_position;
		else if (stack->id == 'b')
			utils->b_rb = n_position;
	}
	else if (n_position > middle)
	{
		if (stack->id == 'a')
			utils->a_rra = (stack->size - n_position);
		else if (stack->id == 'b')
			utils->b_rrb = (stack->size - n_position);
	}
}
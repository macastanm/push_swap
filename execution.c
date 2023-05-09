/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:56:43 by macastan          #+#    #+#             */
/*   Updated: 2023/05/03 15:56:53 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 1;
	min = 0;
	while (stack->size >= i)
	{
		if (i == 1)
			min = stack->top->ct;
		if (stack->top->ct < min)
			min = stack->top->ct;
		stack->top = stack->top->nx;
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 1;
	max = 0;
	while (stack->size >= i)
	{
		if (i == 1)
			max = stack->top->ct;
		if (stack->top->ct > max)
			max = stack->top->ct;
		stack->top = stack->top->nx;
		i++;
	}
	return (max);
}

int	find_match(int n, t_stack *s)
{
	t_stack	*copy;
	int		match;
	int		i;
	int		max;

	copy = copy_stack(s);
	match = find_min(s);
	i = copy->size;
	max = find_max(s);
	if (n > max || n < find_min(s))
	{
		free(copy);
		return (max);
	}
	while (i > 0)
	{
		if (copy->top->ct < n && copy->top->ct > match)
			match = copy->top->ct;
		copy->top = copy->top->nx;
		i--;
	}
	free(copy);
	return (match);
}

void	execute_best(t_utils *utils, t_stack *stack_a, t_stack *stack_b)
{
	while (utils->rrr != 0)
	{
		rrr(stack_a, stack_b);
		utils->rrr--;
	}
	while (utils->rr != 0)
	{
		rr(stack_a, stack_b);
		utils->rr--;
	}
	while (utils->a_ra != 0)
	{
		ra(stack_a);
		utils->a_ra--;
	}
	while (utils->b_rb != 0)
	{
		rb(stack_b);
		utils->b_rb--;
	}
	execute_best2(utils, stack_a, stack_b);
}

void	execute_best2(t_utils *utils, t_stack *stack_a, t_stack *stack_b)
{
	while (utils->a_rra != 0)
	{
		rra(stack_a);
		utils->a_rra--;
	}
	while (utils->b_rrb != 0)
	{
		rrb(stack_b);
		utils->b_rrb--;
	}
	pb(stack_a, stack_b);
}

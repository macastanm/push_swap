/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:43 by macastan          #+#    #+#             */
/*   Updated: 2023/04/27 15:02:54 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *stack, int p)
{
	if (p > 1 && p <= 3)
	{
		while (p > 1)
		{
			ra(stack);
			p--;
		}
	}
	if (p > 3 && p <= 5)
	{
		while (p < (stack->size + 1))
		{
			rra(stack);
			p++;
		}
	}
}

int	find_min(t_stack *stack)
{
	int	p;
	int	min;
	int	i;

	i = 1;
	min = 0;
	p = 0;
	while (stack->size >= i)
	{
		if (i == 1)
		{
			min = stack->top->ct;
			p = 1;
		}
		if (stack->top->ct < min)
		{
			min = stack->top->ct;
			p = i;
		}
		stack->top = stack->top->nx;
		i++;
	}
	return (p);
}

int	find_max(t_stack *stack)
{
	int	p;
	int	max;
	int	i;

	i = 1;
	max = 0;
	p = 0;
	while (stack->size >= i)
	{
		if (i == 1)
		{
			max = stack->top->ct;
			p = 1;
		}
		if (stack->top->ct > max)
		{
			max = stack->top->ct;
			p = i;
		}
		stack->top = stack->top->nx;
		i++;
	}
	return (p);
}

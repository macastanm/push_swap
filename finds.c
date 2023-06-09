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

int	find_position(int n, t_stack *s)
{
	t_stack	*copy;
	int		i;
	int		size;

	copy = copy_stack(s);
	size = s->size;
	i = 0;
	while (i < size)
	{
		if (copy->top->ct == n)
			break ;
		i++;
		copy->top = copy->top->nx;
	}
	free(copy);
	return (i);
}

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

int	find_min_p(t_stack *stack)
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

int	find_max_p(t_stack *stack)
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

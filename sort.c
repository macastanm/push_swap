/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:41:34 by macastan          #+#    #+#             */
/*   Updated: 2023/04/26 14:41:48 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->top->ct > stack_a->top->nx->ct)
		sa(stack_a);
	return ;
}

void	sort_3(t_stack *st_a)
{
	if (check_order(st_a) == 1)
	{
		if (st_a->top->ct > st_a->top->nx->ct && st_a->top->ct
			< st_a->top->pv->ct)
			sa(st_a);
		else if (st_a->top->ct > st_a->top->nx->ct && st_a->top->ct
			> st_a->top->pv->ct && st_a->top->nx->ct > st_a->top->pv->ct)
		{
			sa(st_a);
			rra(st_a);
		}
		else if (st_a->top->ct > st_a->top->nx->ct && st_a->top->ct
			> st_a->top->pv->ct && st_a->top->nx->ct < st_a->top->pv->ct)
			ra(st_a);
		else if (st_a->top->ct < st_a->top->nx->ct && st_a->top->ct
			< st_a->top->pv->ct && st_a->top->nx->ct > st_a->top->pv->ct)
		{
			sa(st_a);
			ra(st_a);
		}
		else
			rra(st_a);
	}
	return ;
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	p;

	p = find_min_p(stack_a);
	rotate_to_top(stack_a, p);
	pb(stack_a, stack_b);
	if (stack_a->size == 4)
	{
		p = find_max_p(stack_a);
		rotate_to_top(stack_a, p);
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	if (stack_a->size == 3 && stack_b->size == 2)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
	if (stack_a->size == 3 && stack_b->size == 1)
		pa(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:26:18 by macastan          #+#    #+#             */
/*   Updated: 2023/04/27 10:27:54 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	stack_a->top = stack_a->top->pv;
	stack_b->top = stack_b->top->pv;
}

void	rra(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->top = stack_a->top->pv;
}

void	rrb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->top = stack_b->top->pv;
}

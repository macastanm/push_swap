/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:05:28 by macastan          #+#    #+#             */
/*   Updated: 2023/04/26 16:05:45 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack_a->top;
	tmp2 = stack_b->top;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	stack_a->top = stack_a->top->nx;
	stack_a->top->nx = tmp;
	stack_b->top = stack_b->top->nx;
	stack_b->top->nx = tmp2;
	write(1, "rr\n", 3);
}

void	sa(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->top;
	if (stack_a->size < 2)
		return ;
	stack_a->top = stack_a->top->nx;
	stack_a->top->nx = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	t_node	*tmp;

	tmp = stack_b->top;
	if (stack_b->size < 2)
		return ;
	stack_b->top = stack_b->top->nx;
	stack_b->top->nx = tmp;
	write(1, "sb\n", 3);
}

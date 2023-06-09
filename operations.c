/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:50:59 by macastan          #+#    #+#             */
/*   Updated: 2023/04/26 15:51:13 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 1)
		return ;
	stack_creat(create_node(stack_b->top->ct), stack_a);
	delete_node(stack_b);
	stack_b->size--;
	write(1, "pa\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	stack_a->top = stack_a->top->nx;
	stack_b->top = stack_b->top->nx;
	write(1, "rr\n", 3);
}

void	ra(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->top = stack_a->top->nx;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->top = stack_b->top->nx;
	write(1, "rb\n", 3);
}

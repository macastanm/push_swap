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

#include "push_swap_bonus.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 1)
		return ;
	stack_creat(create_node(stack_a->top->ct), stack_b);
	delete_node(stack_a);
	stack_a->size--;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	int	tmp2;

	tmp = stack_a->top->ct;
	tmp2 = stack_b->top->ct;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	stack_a->top->ct = stack_a->top->nx->ct;
	stack_a->top->nx->ct = tmp;
	stack_b->top->ct = stack_b->top->nx->ct;
	stack_b->top->nx->ct = tmp2;
}

void	sa(t_stack *stack_a)
{
	int	tmp;

	tmp = stack_a->top->ct;
	if (stack_a->size < 2)
		return ;
	stack_a->top->ct = stack_a->top->nx->ct;
	stack_a->top->nx->ct = tmp;
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	tmp = stack_b->top->ct;
	if (stack_b->size < 2)
		return ;
	stack_b->top->ct = stack_b->top->nx->ct;
	stack_b->top->nx->ct = tmp;
}

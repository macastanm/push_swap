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

void	execute_best(t_utils *utils, t_stack *stack_a, t_stack *stack_b)
{
	while (utils->rrr > 0)
	{
		rrr(stack_a, stack_b);
		utils->rrr--;
	}
	while (utils->rr > 0)
	{
		rr(stack_a, stack_b);
		utils->rr--;
	}
	while (utils->a_ra > 0)
	{
		ra(stack_a);
		utils->a_ra--;
	}
	while (utils->b_rb > 0)
	{
		rb(stack_b);
		utils->b_rb--;
	}
	execute_best2(utils, stack_a, stack_b);
}

void	execute_best2(t_utils *utils, t_stack *stack_a, t_stack *stack_b)
{
	while (utils->a_rra > 0)
	{
		rra(stack_a);
		utils->a_rra--;
	}
	while (utils->b_rrb > 0)
	{
		rrb(stack_b);
		utils->b_rrb--;
	}
	pb(stack_a, stack_b);
}
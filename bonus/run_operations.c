/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:25:34 by macastan          #+#    #+#             */
/*   Updated: 2023/05/09 10:26:05 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	run_operations(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[0] == 's')
	{
		if (line[1] == 'a')
			sa(stack_a);
		else if (line[1] == 'b')
			sb(stack_b);
		else if (line[1] == 's')
			ss(stack_a, stack_b);
	}
	else if (line[0] == 'p')
	{
		if (line[1] == 'a')
			pa(stack_a, stack_b);
		else if (line[1] == 'b')
			pb(stack_a, stack_b);
	}
	run_operations2(line, stack_a, stack_b);
}

void	run_operations2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[0] == 'r' && line[1] == 'r')
	{
		if (line[2] == 'a')
			rra(stack_a);
		else if (line[2] == 'b')
			rrb(stack_b);
		else if (line[2] == 'r')
			rrr(stack_a, stack_b);
	}
	else if (line[0] == 'r')
	{
		if (line[1] == 'a')
			ra(stack_a);
		else if (line[1] == 'b')
			rb(stack_b);
		else if (line[1] == 'r')
			rr(stack_a, stack_b);
	}
	else
		return ;
}
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

int	run_operations(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[0] == 's')
	{
		if (line[1] == 'a' && line[2] == '\n')
		{
			sa(stack_a);
			return (0);
		}
		else if (line[1] == 'b' && line[2] == '\n')
		{
			sb(stack_b);
			return (0);
		}
		else if (line[1] == 's' && line[2] == '\n')
		{
			ss(stack_a, stack_b);
			return (0);
		}
	}
	if (run_operations2(line, stack_a, stack_b) == 1)
		return (1);
	return (0);
}

int	run_operations2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[0] == 'r' && line[1] == 'r')
	{
		if (line[2] == 'a' && line[3] == '\n')
		{
			rra(stack_a);
			return (0);
		}
		else if (line[2] == 'b' && line[3] == '\n')
		{
			rrb(stack_b);
			return (0);
		}
		else if (line[2] == 'r' && line[3] == '\n')
		{
			rrr(stack_a, stack_b);
			return (0);
		}
	}
	if (run_operations3(line, stack_a, stack_b) == 1)
		return (1);
	return (0);
}

int	run_operations3(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[0] == 'r')
	{
		if (line[1] == 'a' && line[2] == '\n')
		{
			ra(stack_a);
			return (0);
		}
		else if (line[1] == 'b' && line[2] == '\n')
		{
			rb(stack_b);
			return (0);
		}
		else if (line[1] == 'r' && line[2] == '\n')
		{
			rr(stack_a, stack_b);
			return (0);
		}
	}
	if (run_operations4(line, stack_a, stack_b) == 1)
		return (1);
	return (0);
}

int	run_operations4(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (line[0] == 'p')
	{
		if (line[1] == 'a' && line[2] == '\n')
		{
			pa(stack_a, stack_b);
			return (0);
		}
		else if (line[1] == 'b' && line[2] == '\n')
		{
			pb(stack_a, stack_b);
			return (0);
		}
	}
	write(2, "Error\n", 6);
	return (1);
}

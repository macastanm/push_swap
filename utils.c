/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:02:45 by macastan          #+#    #+#             */
/*   Updated: 2023/05/03 11:02:56 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *copy_stack(t_stack *a)
{
	t_stack *copy;

	copy = malloc(sizeof (t_stack));
	copy->size = a->size;
	copy->top = a->top;
	return (copy);
}

int sum_moves(t_utils *utils)
{
	int total;

	total = 0;
	check_rrr(utils);
	if (utils->a_rra != 0)
		total = total + utils->a_rra;
	if (utils->a_ra != 0)
		total = total + utils->a_ra;
	if (utils->b_rrb != 0)
		total = total + utils->b_rrb;
	if (utils->b_rb != 0)
		total = total + utils->b_rb;
	if (utils->rr != 0)
		total = total + utils->rr;
	if (utils->rrr != 0)
		total = total + utils->rrr;
	return (total);
}

void	check_rrr(t_utils *utils)
{
	while (utils->a_ra >= 1 && utils->b_rb >= 1)
	{
		utils->rr += 1;
		utils->a_ra -= 1;
		utils->b_rb -= 1;
	}
	while (utils->a_rra >= 1 && utils->b_rrb >= 1)
	{
		utils->rrr += 1;
		utils->a_rra -= 1;
		utils->b_rrb -= 1;
	}
}

int check_best(t_utils *best, t_utils *utils)
{
	if (sum_moves(utils) == 0)
	{
		*best = *utils;
		return (0);
	}
	if (best->sum > sum_moves(utils))
	{
		*best = *utils;
		best->sum = sum_moves(utils);
	}
	return (1);
}

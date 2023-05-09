/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:30:06 by macastan          #+#    #+#             */
/*   Updated: 2023/04/20 15:30:18 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	delete_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->top = stack->top->nx;
	stack->top->pv->pv->nx = stack->top;
	stack->top->pv = stack->top->pv->pv;
	free(tmp);
}

void	free_the_list(t_stack *stack)
{
	while (stack->size > 0)
	{
		delete_node(stack);
		stack->size--;
	}
}

void	free_the_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	i -= 1;
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

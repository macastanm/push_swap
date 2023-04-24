/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:33:41 by macastan          #+#    #+#             */
/*   Updated: 2023/04/20 15:33:50 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int nbr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->ct = nbr;
	new->pv = NULL;
	new->nx = NULL;
	return (new);
}

void	stack_creat(t_node *new_node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->top->nx = new_node;
		stack->top->pv = new_node;
		stack->size += 1;
		return ;
	}
	new_node->nx = stack->top;
	new_node->pv = stack->top->pv;
	stack->top->pv->nx = new_node;
	stack->top->pv = new_node;
	stack->top = new_node;
	stack->size += 1;
}

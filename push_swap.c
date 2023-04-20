/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:50:21 by macastan          #+#    #+#             */
/*   Updated: 2023/04/20 12:50:24 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%i\n", stack->top->ct);
		stack->top = stack->top->nx;
		i++;
	}
}

void	break_arg(char *argv, t_stack *stack_a)
{
	char **split;
	int i;
	int j;

	i = 0;
	j = 0;
	split = ft_split(argv, ' ');
	while (split[i])
		i++;
	i -= 1;
	while (i >= 0)
	{
		j = ft_atoi(split[i]);
		stack_creat(create_node(j), stack_a);
		i--;
	}
	free_the_split(split);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	//t_stack stack_b;
	int j;
	int	i;

	stack_a.size = 0;
	j = 0;
	i = argc;
	if (argc < 2)
	{
		ft_printf("Wrong number of arguments!\n");
		return (0);
	}
	else if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') == 0)
			return (0);
		else
			break_arg(argv[1], &stack_a);
	}
	else
	{
		while (argc > 1)
		{
			j = ft_atoi(argv[--i]);
			stack_creat(create_node(j), &stack_a);
			argc--;
		}
	}
	print_list(&stack_a);
	return (0);
}

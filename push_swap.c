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

/*void	check_size(int size)
{

}*/

void	multiple_args(int argc, char **argv, t_stack *stack_a)
{
	int		j;
	int		i;

	j = 0;
	i = argc;
	while (argc > 1)
	{
		j = ft_atoi(argv[--i]);
		stack_creat(create_node(j), stack_a);
		argc--;
	}
	return ;
}

void	break_arg(char *argv, t_stack *stack_a)
{
	char	**split;
	int		j;
	int		i;

	j = 0;
	i = 0;
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
	int		j;
	int		i;

	stack_a.size = 0;
	j = 0;
	i = argc;
	if (argc < 2)
		return (write(2, "Error\n", 6));
	if (check_content(&*argv, argc) != 1)
		return (write(2, "Error\n", 6));
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') == 0)
			return (0);
		else
			break_arg(argv[1], &stack_a);
	}
	else
		multiple_args(argc, &*argv, &stack_a);
	//check_order(stack_a);
	//check_size(stack_a.size);
	print_list(&stack_a);
	return (0);
}

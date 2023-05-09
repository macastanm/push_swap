/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:37:29 by macastan          #+#    #+#             */
/*   Updated: 2023/05/08 10:37:47 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	run_checker(t_stack *stack_a)
{
	t_stack	stack_b;
	char *line;

	stack_b.size = 0;
	while ((line = get_next_line(0)))
		run_operations(line, stack_a, &stack_b);
	if (check_order(stack_a) == 0 && stack_b.size == 0)
	{
		free(line);
		return (write(2, "OK\n", 3));
	}
	else
	{
		free_the_list(&stack_b);
		free(line);
		return (write(2, "KO\n", 3));
	}
}

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

int main(int argc, char **argv)
{
	t_stack stack_a;

	stack_a.size = 0;
	if (argc < 2)
		return (0);
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
	if (check_order(&stack_a) != 1)
	{
		free_the_list(&stack_a);
		return (write(2, "OK\n", 3));
	}
	run_checker(&stack_a);
	free_the_list(&stack_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:33:27 by macastan          #+#    #+#             */
/*   Updated: 2023/04/24 11:33:38 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[j]) == ft_atoi(arr[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_num(char **arr, int i, int j)
{
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (ft_strchr(" -0123456789", arr[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_content(char **argv, int argc)
{
	char	**arr;

	arr = 0;
	if (check_num(argv, 1, 0) != 1)
		return (0);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (check_max(&*arr) != 1 || check_dup(&*arr) != 1)
		{
			free_the_split(arr);
			return (0);
		}
		free_the_split(arr);
	}
	else
	{
		if (check_max(argv) != 1 || check_dup(argv) != 1)
			return (0);
	}
	return (1);
}

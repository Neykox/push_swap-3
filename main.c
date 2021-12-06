/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:38:10 by aleroy            #+#    #+#             */
/*   Updated: 2021/08/02 11:38:12 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *stack, int argc, int w)
{
	int	i;

	i = 0;
	if (w == 1)
	{
		while (i + 1 < argc - 1)
		{
			if (stack[i] < stack[i + 1])
				i++;
			else
				return (0);
		}
	}
	else if (w == 2)
	{
		while (i + 1 < argc - 1)
		{
			if (stack[i] > stack[i + 1])
				i++;
			else
				return (0);
		}
	}
	return (1);
}

int	*create_tab_b(t_info *info)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * info->size_a);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

int	prep_stacks(t_info *info, int argc, char **argv)
{
	info->stop = 0;
	info->size_a = 0;
	info->stack_a = check_arg(argc, argv, 1, info);
	if (info->stack_a == NULL || info->stop == 1)
	{
		if (info->stop == 1)
			free(info->stack_a);
		return (-1);
	}
	info->size_b = 0;
	info->stack_b = create_tab_b(info);
	if (info->stack_b == NULL)
		return (-1);
	if (info->size_a > 70)
	{
		if (info->size_a < 300)
			info->size_s = 10;
		else
			info->size_s = 25;
		info->stack_s = malloc(sizeof(int) * info->size_s);
		if (info->stack_s == NULL)
			return (-1);
	}
	return (0);
}

void	destroyer(t_info *info)
{
	if (info->size_a > 70)
		free(info->stack_s);
	free(info->stack_a);
	free(info->stack_b);
	free(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	info = malloc(sizeof(t_info));
	if (info == NULL)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (prep_stacks(info, argc, argv) == -1)
	{
		free(info);
		write(1, "Error\n", 6);
		return (-1);
	}
	if (info->size_a > 70)
		sort_p2(info);
	else
		sort_p1(info);
	destroyer(info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:28:19 by aleroy            #+#    #+#             */
/*   Updated: 2021/08/23 14:28:22 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaper(int *stack, int size, int a)
{
	int	temp;

	if (size >= 2)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
	if (a == 1 && size >= 2)
		write(1, "sa\n", 3);
	else if (a == 2 && size >= 2)
		write(1, "sb\n", 3);
	else if (a == 3 && size >= 2)
		write(1, "ss\n", 3);
}

void	push_to_b(t_info *info, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	if (info->size_a <= 0)
		return ;
	while (i < info->size_b)
		i++;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = stack_a[i];
	while (i + 1 < info->size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	info->size_a--;
	info->size_b++;
	write(1, "pb\n", 3);
}

void	push_to_a(t_info *info, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	if (info->size_b <= 0)
		return ;
	while (i < info->size_a)
		i++;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = stack_b[i];
	while (i + 1 < info->size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	info->size_b--;
	info->size_a++;
	write(1, "pa\n", 3);
}

void	rotater(int *stack, int size, int a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[i];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	if (a == 1)
		write(1, "ra\n", 3);
	else if (a == 2)
		write(1, "rb\n", 3);
	else if (a == 3)
		write(1, "rr\n", 3);
}

void	rrotater(int *stack, int size, int a)
{
	int	i;
	int	temp;

	i = size - 1;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
	if (a == 1)
		write(1, "rra\n", 4);
	else if (a == 2)
		write(1, "rrb\n", 4);
	else if (a == 3)
		write(1, "rrr\n", 4);
}

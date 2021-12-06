/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:25:36 by aleroy            #+#    #+#             */
/*   Updated: 2021/10/05 18:25:38 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smalls(t_info *info, int i, int k)
{
	info->stack_s[i] = info->stack_a[i];
	while (i < info->size_a)
	{
		if (info->stack_a[i] < info->stack_s[k])
			info->stack_s[k] = info->stack_a[i];
		i++;
	}
	k = 1;
	while (k < info->size_s)
		info->stack_s[k++] = 2147483647;
	k = 1;
	i = 0;
	while (k < info->size_s)
	{
		if (info->stack_a[i] < info->stack_s[k]
			&& info->stack_a[i] > info->stack_s[k - 1])
			info->stack_s[k] = info->stack_a[i];
		i++;
		if (i == info->size_a)
		{
			k++;
			i = 0;
		}
	}
}

int	in_smalls(t_info *info, int f)
{
	int	i;

	i = 0;
	while (i < info->size_s)
	{
		if (info->stack_s[i] == f)
			return (1);
		i++;
	}
	return (-1);
}

void	rotationner2(t_info *info, int i)
{
	if (info->spos < info->size_a / 2)
	{
		if (info->stack_a[0] > info->stack_a[1]
			&& in_smalls(info, info->stack_a[1]) == 0
			&& info->stack_a[0] != info->big)
			swaper(info->stack_a, info->size_a, 1);
		if (i == 1)
		{
			rotater(info->stack_b, info->size_b, 0);
			rotater(info->stack_a, info->size_a, 3);
		}
		else if (i == 2)
		{
			rotater(info->stack_a, info->size_a, 1);
			rrotater(info->stack_b, info->size_b, 2);
		}
		else
			rotater(info->stack_a, info->size_a, 1);
	}
	else
		rotationner2_2(info, i);
}

void	rotationner2_2(t_info *info, int i)
{
	if (info->stack_a[0] > info->stack_a[1]
		&& in_smalls(info, info->stack_a[1]) == 0
		&& info->stack_a[0] != info->big)
		swaper(info->stack_a, info->size_a, 1);
	if (i == 1)
	{
		rrotater(info->stack_a, info->size_a, 1);
		rotater(info->stack_b, info->size_b, 2);
	}
	else if (i == 2)
	{
		rrotater(info->stack_a, info->size_a, 3);
		rrotater(info->stack_b, info->size_b, 0);
	}
	else
		rrotater(info->stack_a, info->size_a, 1);
}

int	find_big_b(t_info *info)
{
	int	i;
	int	big_pos;

	i = 0;
	big_pos = 0;
	info->big = info->stack_b[i];
	info->small = info->stack_b[i];
	while (i < info->size_b)
	{
		if (info->stack_b[i] > info->big)
		{
			info->big = info->stack_b[i];
			big_pos = i;
		}
		if (info->stack_b[i] < info->small)
			info->small = info->stack_b[i];
		i++;
	}
	return (big_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:30:39 by aleroy            #+#    #+#             */
/*   Updated: 2021/10/05 18:30:41 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_b_spot(t_info *info, int big_pos)
{
	if (info->ns > info->big || info->ns < info->small)
	{
		if (info->stack_b[0] != info->big)
		{
			if (big_pos < info->size_b / 2)
				return (1);
			else
				return (2);
		}
	}
	else
	{
		find_b_spot_2(info, 0, 0);
		if (info->stack_b[info->size_b - 1] != info->b_target)
		{
			if (info->bpos < info->size_b / 2)
				return (1);
			else
				return (2);
		}
	}
	return (0);
}

void	find_b_spot_2(t_info *info, int i, int rot)
{
	while (info->stack_b[0] != info->big)
	{
		rotater(info->stack_b, info->size_b, 0);
		rot++;
	}
	while (i < info->size_b)
	{
		if (info->stack_b[i] > info->ns)
			info->b_target = info->stack_b[i];
		i++;
	}
	while (rot != 0)
	{
		rrotater(info->stack_b, info->size_b, 0);
		rot--;
	}
	i = 0;
	while (i < info->size_b)
	{
		if (info->b_target == info->stack_b[i])
			info->bpos = i;
		i++;
	}
}

void	find_ns(t_info *info)
{
	int	i;

	i = 0;
	if (in_smalls(info, info->stack_a[0]) == 1 && i < info->size_a)
		;
	else if (info->spos < info->size_a / 2)
	{
		i = 0;
		while ((in_smalls(info, info->stack_a[i]) == -1) && i < info->size_a)
			i++;
	}
	else
	{
		i = info->size_a - 1;
		while ((in_smalls(info, info->stack_a[i]) == -1) && i > 0)
			i--;
	}
	info->ns = info->stack_a[i];
}

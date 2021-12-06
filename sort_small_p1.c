/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:50:52 by aleroy            #+#    #+#             */
/*   Updated: 2021/09/15 18:50:56 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_spos(t_info *info)
{
	int	i;
	int	small;

	i = 0;
	small = info->stack_a[i];
	info->spos = i;
	while (i < info->size_a)
	{
		if (info->stack_a[i] < small)
		{
			small = info->stack_a[i];
			info->spos = i;
		}
		i++;
	}
}

void	find_limit(t_info *info, int i)
{
	info->small = info->stack_a[i];
	info->ns = info->stack_a[i];
	info->big = info->stack_a[i];
	while (i < info->size_a)
	{
		if (info->stack_a[i] < info->small)
		{
			info->small = info->stack_a[i];
			info->spos = i;
		}
		if (info->stack_a[i] > info->big)
			info->big = info->stack_a[i];
		i++;
	}
	if (info->small == info->ns)
		info->ns = 2147483647;
	i = 0;
	while (i < info->size_a)
	{
		if (info->stack_a[i] < info->ns && info->stack_a[i] > info->small)
			info->ns = info->stack_a[i];
		i++;
	}
}

void	rotationner(t_info *info)
{
	if (info->spos < info->size_a / 2)
	{
		while (info->stack_a[0] != info->small)
		{
			if (info->stack_a[0] > info->stack_a[1]
				&& info->stack_a[1] != info->small
				&& info->stack_a[0] != info->big)
				swaper(info->stack_a, info->size_a, 1);
			rotater(info->stack_a, info->size_a, 1);
		}
	}
	else
	{
		while (info->stack_a[0] != info->small)
		{
			if (info->stack_a[0] > info->stack_a[1]
				&& info->stack_a[1] != info->small
				&& info->stack_a[0] != info->big)
				swaper(info->stack_a, info->size_a, 1);
			rrotater(info->stack_a, info->size_a, 1);
		}
	}
}

void	rotationner_p2(t_info *info)
{
	if (info->spos < info->size_a / 2)
	{
		while (info->stack_a[0] != info->small || info->stack_a[0] == info->ns)
		{
			if (info->stack_a[0] > info->stack_a[1]
				&& info->stack_a[1] != info->small
				&& info->stack_a[0] != info->big)
				swaper(info->stack_a, info->size_a, 1);
			rotater(info->stack_a, info->size_a, 1);
		}
	}
	else
	{
		while (info->stack_a[0] != info->small || info->stack_a[0] == info->ns)
		{
			if (info->stack_a[0] > info->stack_a[1]
				&& info->stack_a[1] != info->small
				&& info->stack_a[0] != info->big)
				swaper(info->stack_a, info->size_a, 1);
			rrotater(info->stack_a, info->size_a, 1);
		}
	}
}

void	hard_coded(t_info *info)
{
	if ((info->stack_a[0] == info->ns && info->stack_a[1] == info->small)
		|| (info->stack_a[1] == info->ns && info->stack_a[2] == info->small)
		|| (info->stack_a[0] == info->small && info->stack_a[2] == info->ns))
	{
		swaper(info->stack_a, info->size_a, 1);
	}
	rotationner(info);
}

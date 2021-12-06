/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_p3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:53:11 by aleroy            #+#    #+#             */
/*   Updated: 2021/10/05 18:53:13 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

void	sort_p2_2(t_info *info)
{
	while (info->size_b > 1 && find_b_spot(info, find_big_b(info)) != 0)
	{
		if (find_b_spot(info, find_big_b(info)) == 1)
			rotater(info->stack_b, info->size_b, 2);
		else if (find_b_spot(info, find_big_b(info)) == 2)
			rrotater(info->stack_b, info->size_b, 2);
	}
	push_to_b(info, info->stack_a, info->stack_b);
	if (info->size_a == 0)
		return ;
	if (info->stack_b[0] == info->stack_s[0])
		find_smalls(info, 0, 0);
	find_spos(info);
	find_ns(info);
}

void	sort_p2(t_info *info)
{
	find_limit(info, 0);
	find_smalls(info, 0, 0);
	find_spos(info);
	find_ns(info);
	while (info->size_a >= 1)
	{
		while (in_smalls(info, info->stack_a[0]) == 1 && info->size_a >= 1)
			sort_p2_2(info);
		if (info->size_a == 0)
		{
			if (check_sort(info->stack_b, info->size_b + 1, 2) == 0)
				sort_b(info);
			while (info->size_b > 0)
				push_to_a(info, info->stack_a, info->stack_b);
			break ;
		}
		if (info->size_b > 1)
			rotationner2(info, find_b_spot(info, find_big_b(info)));
		else
			rotationner2(info, 0);
	}
}

void	sort_b(t_info *info)
{
	int	i;
	int	big;
	int	big_pos;

	i = 0;
	big = info->stack_b[i];
	while (i < info->size_b)
	{
		if (info->stack_b[i] > big)
		{
			big_pos = i;
			big = info->stack_b[i];
		}
		i++;
	}
	while (info->stack_b[0] != big)
	{
		if (big_pos < info->size_b / 2)
			rotater(info->stack_b, info->size_b, 2);
		else
			rrotater(info->stack_b, info->size_b, 2);
	}
}

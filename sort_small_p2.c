/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:58:41 by aleroy            #+#    #+#             */
/*   Updated: 2021/10/05 18:58:43 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_p1_2(t_info *info)
{
	if (info->stack_a[0] == info->ns)
	{
		push_to_b(info, info->stack_a, info->stack_b);
		find_spos(info);
		rotationner(info);
		push_to_b(info, info->stack_a, info->stack_b);
	}
	else
		push_to_b(info, info->stack_a, info->stack_b);
	if (info->stack_b[0] < info->stack_b[1] && info->size_b >= 2)
		swaper(info->stack_b, info->size_b, 2);
	find_limit(info, 0);
}

void	sort_p1(t_info *info)
{
	find_limit(info, 0);
	if (info->size_a == 5)
			if (hard_coded_five(info, 0, 0) == 1)
				return ;
	while (check_sort(info->stack_a, info->size_a + 1, 1) == 0)
	{
		if (info->size_a <= 3)
			hard_coded(info);
		while ((info->stack_a[0] == info->small
				|| info->stack_a[0] == info->ns) && info->size_a > 3
			&& check_sort(info->stack_a, info->size_a + 1, 1) == 0)
			sort_p1_2(info);
		rotationner_p2(info);
		if (check_sort(info->stack_a, info->size_a + 1, 1) == 1)
			while (info->size_b > 0)
				push_to_a(info, info->stack_a, info->stack_b);
	}
}

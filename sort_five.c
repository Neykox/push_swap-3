/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:39:32 by aleroy            #+#    #+#             */
/*   Updated: 2021/12/05 21:39:33 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_to_b_five(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	i = 0;
	while (i < *size_b)
		i++;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = stack_a[i];
	while (i + 1 < *size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	size_a--;
	size_b++;
}

void	push_to_a_five(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	i = 0;
	while (i < *size_a)
		i++;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = stack_b[i];
	while (i + 1 < *size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	size_b--;
	size_a++;
}


void	rotationner_five(t_five *five)
{
	if (five->spos < five->size_a / 2)
	{
		while (five->stack_a[0] != five->small)
		{
			if (five->stack_a[0] > five->stack_a[1]
				&& five->stack_a[1] != five->small
				&& five->stack_a[0] != five->big)
			{
				swaper(five->stack_a, five->size_a, 0);
				five_result(five, "sa\n\0");
			}
			if (five->size_b == 2 && five->stack_b[0] < five->stack_b[1])
			{
				rotater(five->stack_b, five->size_b, 0);
				rotater(five->stack_a, five->size_a, 0);
				five_result(five, "rr\n\0");
			}
			else
			{
				rotater(five->stack_a, five->size_a, 1);
				five_result(five, "ra\n\0");
			}
		}
	}
	else
	{
		while (five->stack_a[0] != five->small)
		{
			if (five->stack_a[0] > five->stack_a[1]
				&& five->stack_a[1] != five->small
				&& five->stack_a[0] != five->big)
			{
				swaper(five->stack_a, five->size_a, 0);
				five_result(five, "sa\n\0");
			}
			if (five->size_b == 2 && five->stack_b[0] < five->stack_b[1])
			{
				rrotater(five->stack_b, five->size_b, 0);
				rrotater(five->stack_a, five->size_a, 0);
				five_result(five, "rrr\n\0");
			}
			else
			{
				rrotater(five->stack_a, five->size_a, 0);
				five_result(five, "rra\n\0");
			}
		}
	}
}

void	hard_coded_five_2(t_five *five)
{
	if ((five->stack_a[0] == five->ns && five->stack_a[1] == five->small)
		|| (five->stack_a[1] == five->ns && five->stack_a[2] == five->small)
		|| (five->stack_a[0] == five->small && five->stack_a[2] == five->ns))
	{
		if (five->size_b == 2 && five->stack_b[0] < five->stack_b[1])
		{
			swaper(five->stack_a, five->size_a, 3);//ss
			swaper(five->stack_b, five->size_b, 0);
			five_result(five, "ss\n\0");
		}
		else
		{
			swaper(five->stack_a, five->size_a, 1);//sa
			five_result(five, "sa\n\0");
		}
	}
	rotationner_five(five);
}

void	find_limit_five(t_five *five, int i)
{
	five->small = five->stack_a[i];
	five->ns = five->stack_a[i];
	five->big = five->stack_a[i];
	while (i < five->size_a)
	{
		if (five->stack_a[i] < five->small)
		{
			five->small = five->stack_a[i];
			five->spos = i;
		}
		if (five->stack_a[i] > five->big)
			five->big = five->stack_a[i];
		i++;
	}
	if (five->small == five->ns)
		five->ns = 2147483647;
	i = 0;
	while (i < five->size_a)
	{
		if (five->stack_a[i] < five->ns && five->stack_a[i] > five->small)
			five->ns = five->stack_a[i];
		i++;
	}
}

void	prep_five(t_info *info, t_five *five)
{
	int	i;

	i = 0;
	while (i < info->size_a)
	{
		five->stack_a[i] = info->stack_a[i];
		i++;
	}
	five->size_a = 5;
	five->size_b = 0;
	five->action = 0;
	five->result[0] = '\0';
	five->i = 0;
}

// void	five_result(char *res, int *i, char *added, int *action)
// {
// 	int	r;

// 	r = 0;
// 	while (added[r])
// 	{
// 		res[*i] = added[r];
// 		i++;
// 		r++;
// 	}
// 	action++;
// 	printf("%s\n%d\n", res, *action);
// }

void	five_result(t_five *five, char *added)
{
	int a;

	a = 0;
	printf("added = %s\nresult = %s\n", added, five->result);
	while (added[a])
	{
		five->result[five->i] = added[a];
		five->i = five->i + 1;
		a++;
	}
	five->action = five->action + 1;
}

int	hard_coded_five(t_info *info, int i, int ns_pos)
{
	t_five	five;

	prep_five(info, &five);

	find_limit_five(&five, 0);
	while (i < five.size_a)
	{
		if (five.ns == five.stack_a[i])
			ns_pos = i;
		i++;
	}

	while (five.size_a > 3)
	{
		while (five.stack_a[0] == five.small || five.stack_a[0] == five.ns)
		{
			push_to_b_five(five.stack_a, five.stack_b, &five.size_a, &five.size_b);
			five_result(&five, "pb\n\0");
		}
		if (five.size_b < 2)
		{
			if (five.spos < five.size_a / 2 && ns_pos < five.size_a / 2)
			{
					rotater(five.stack_a, five.size_a, 0);//ra
					five_result(&five, "ra\n\0");
			}
			else
			{
					rrotater(five.stack_a, five.size_a, 0);//rra
					five_result(&five, "rra\n\0");
			}
		}
	}
	find_limit_five(&five, 0);
	hard_coded_five_2(&five);
	if (five.size_b == 2 && five.stack_b[0] < five.stack_b[1])
	{
		swaper(five.stack_b, five.size_b, 0);
		five_result(&five, "sb\n\0");
	}
	while (five.size_b > 0)
	{
		push_to_a_five(five.stack_a, five.stack_b, &five.size_a, &five.size_b);
		five_result(&five, "pa\n\0");
	}

	if (five.action <= 12)
		write(1, five.result, five.i);
	else
		return (-1);
	return (1);

	// while (info->size_a > 3)
	// {
	// 	while (info->stack_a[0] == info->small || info->stack_a[0] == info->ns)
	// 		push_to_b(info, info->stack_a, info->stack_b);
	// 	if (info->size_b < 2)
	// 	{
	// 		if (info->spos < info->size_a / 2 && ns_pos < info->size_a / 2)
	// 				rotater(info->stack_a, info->size_a, 1);
	// 		else
	// 				rrotater(info->stack_a, info->size_a, 1);
	// 	}
	// }
	// find_limit(info, 0);
	// hard_coded_five_2(info);
	// if (info->size_b == 2 && info->stack_b[0] < info->stack_b[1])
	// 	swaper(info->stack_b, info->size_b, 2);
	// while (info->size_b > 0)
	// 			push_to_a(info, info->stack_a, info->stack_b);
	// i = 0;
	// while (i < info->size_a)
	// {
	// 	printf("%d\n", info->stack_a[i]);
	// 	i++;
	// }
}

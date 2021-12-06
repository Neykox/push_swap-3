/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:43:56 by aleroy            #+#    #+#             */
/*   Updated: 2021/08/02 11:43:58 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
// #include <string.h>

typedef struct s_five
{
	int			stack_a[5];
	int			stack_b[5];
	int			size_a;
	int			size_b;
	int			action;
	char		result[100];
	int			i;
	int			small;
	int			spos;
	int			ns;
	int			big;
}				t_five;

typedef struct s_info
{
	int			*stack_a;
	int			*stack_b;
	int			*stack_s;
	int			size_a;
	int			size_b;
	int			size_s;
	int			k;
	int			stop;
	int			small;
	int			spos;
	int			ns;
	int			big;
	int			b_target;
	int			bpos;
	int			b;
}				t_info;

void	push_to_b_five(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	push_to_a_five(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	rotationner_five(t_five *five);
void	hard_coded_five_2(t_five *five);
void	find_limit_five(t_five *five, int i);
void	prep_five(t_info *info, t_five *five);
// void	five_result(char *res, int *i, char *added, int *action);
void	five_result(t_five *five, char *added);
int	hard_coded_five(t_info *info, int i, int ns_pos);

long int	ft_atoi_mod(const char *str, t_info *info);
int			check_num(char *str);
int			*check_arg(int argc, char **av, int i, t_info *info);
int			create_tab_a(int argc, char **argv, t_info *info, int *tmp);
int			*create_tab(int argc, char **argv, t_info *info, int *tmp);
// int			*create_tab(int argc, char **argv, t_info *info, int b);

void		swaper(int *stack, int size, int a);
void		push_to_b(t_info *info, int *stack_a, int *stack_b);
void		push_to_a(t_info *info, int *stack_a, int *stack_b);
void		rotater(int *stack, int size, int a);
void		rrotater(int *stack, int size, int a);

void		find_spos(t_info *info);
void		find_limit(t_info *info, int i);
void		rotationner(t_info *info);
void		rotationner_p2(t_info *info);
void		hard_coded(t_info *info);

void		sort_p1_2(t_info *info);
void		sort_p1(t_info *info);

void		sort_p2_2(t_info *info);
void		sort_p2(t_info *info);
void		sort_b(t_info *info);

int			find_b_spot(t_info *info, int big_pos);
void		find_b_spot_2(t_info *info, int i, int rot);
void		find_b_spot_3(t_info *info, int *tmp);
void		find_ns(t_info *info);

void		find_smalls(t_info *info, int i, int k);
int			in_smalls(t_info *info, int f);
void		rotationner2(t_info *info, int i);
void		rotationner2_2(t_info *info, int i);
int			find_big_b(t_info *info);

int			check_sort(int *stack, int argc, int w);
int			*create_tab_b(t_info *info);
int			prep_stacks(t_info *info, int argc, char **argv);
int			main(int argc, char **argv);

#endif

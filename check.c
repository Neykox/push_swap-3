/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleroy <aleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:14:49 by aleroy            #+#    #+#             */
/*   Updated: 2021/08/09 16:14:51 by aleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_mod(const char *str, t_info *info)
{
	int			j;
	long int	result;
	int			sign;

	j = 0;
	sign = 1;
	result = 0;
	while (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			sign = sign * -1;
		j++;
	}
	while (str[j] != '\0' && str[j] != ' ' && str[j] >= '0' && str[j] <= '9')
	{
		result = (result * 10) + (str[j] - 48);
		j++;
		if (result * sign > 2147483647 || result * sign < -2147483648)
		{
			info->stop = 1;
			return (0);
		}
	}
	return (result * sign);
}

int	check_num(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\0')
			return (size);
		while (str[i] && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] == '\0' || !(str[i] >= '0' && str[i] <= '9'))
			return (size);
		if (str[i] >= '0' && str[i] <= '9')
			size++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (size);
}

int	*check_arg(int argc, char **av, int i, t_info *info)
{
	while (i < argc)
	{
		info->k = 0;
		while (av[i][info->k])
		{
			if (!((av[i][info->k] >= '0' && av[i][info->k] <= '9')
				|| av[i][info->k] == '-' || av[i][info->k] == '+'
				|| av[i][info->k] == ' '))
				return (NULL);
			info->k++;
		}
		info->size_a = info->size_a + check_num(av[i]);
		i++;
	}
	if (info->size_a <= 0)
	{
		return (NULL);
	}
	return (create_tab(argc, av, info, create_tab_b(info)));
}

int	create_tab_a(int argc, char **argv, t_info *info, int *tmp)
{
	int			b;
	int			n;
	int			i;

	n = 0;
	i = 1;
	while (i < argc && info->stop == 0)
	{
		b = 0;
		while (argv[i][b])
		{
			while (argv[i][b] == ' ' && argv[i][b])
				b++;
			if (argv[i][b] && check_num(argv[i]) > 0)
			{
				tmp[n] = ft_atoi_mod(&argv[i][b], info);
				n++;
			}
			while (argv[i][b] != ' ' && argv[i][b])
				b++;
		}
		i++;
	}
	return (1);
}

int	*create_tab(int argc, char **argv, t_info *info, int *tmp)
{
	if (tmp == NULL)
		return (NULL);
	argc = create_tab_a(argc, argv, info, tmp);
	if (info->stop == 1)
		return (tmp);
	info->b = 0;
	while (info->b < info->size_a)
	{
		while (argc < info->size_a)
		{
			if (tmp[argc] == tmp[info->b])
			{
				free(tmp);
				return (NULL);
			}
			argc++;
		}
		if (argc == info->size_a)
		{
			info->b++;
			argc = info->b + 1;
		}
	}
	return (tmp);
}

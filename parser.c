/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:40:22 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/08 23:40:22 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fits_in_int(char *s)
{
	int		neg;
	long	value;

	if (*s == '\0')
		return (0);
	neg = (*s == '-');
	if (*s == '-' || *s == '+')
		s++;
	value = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		if (!neg && (value > 2147483647L / 10 || \
(value == 2147483647L / 10 && (*s - '0') > 2147483647L % 10)))
			return (0);
		else if (neg && (value > 2147483648L / 10 || \
(value == 2147483648L / 10 && (*s - '0') > 2147483648L % 10)))
			return (0);
		value = value * 10 + (*s - '0');
		s++;
	}
	return (1);
}

int	is_duplicated(int *arr, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i <= max)
	{
		j = 0;
		while (j <= max)
		{
			if (arr[i] == arr[j] && (i != j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (!str[0])
		return (0);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == ' ' || \
str[i] == '+' || str[i] == '-'))
	{
		if (ft_isdigit(str[i]))
			status = 1;
		i++;
	}
	if (!status)
		return (0);
	return (!str[i]);
}

static int	process_arg(char *arg, t_stack *s)
{
	char	**split;
	int		j;

	if (!arg || !is_number(arg))
		return (1);
	split = ft_split(arg, ' ');
	if (!split)
		return (1);
	j = 0;
	while (split[j])
		j++;
	while (j > 0)
	{
		j--;
		if (!fits_in_int(split[j]) || !push(ft_atoi(split[j]), s))
		{
			while (j >= 0)
				free(split[j--]);
			free(split);
			return (1);
		}
		free(split[j]);
	}
	free(split);
	return (0);
}

int	parse_stack_input(char **args, int count, t_stack *s)
{
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		if (process_arg(args[i], s))
			return (1);
		i--;
	}
	if (is_duplicated(s->arr, s->stack_top_idx))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:37:56 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/08 23:37:56 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "ft_printf.h"

static int	is_sorted(t_stack *a)
{
	int	max;
	int	i;

	i = 0;
	max = INT_MAX;
	while (i <= a->stack_top_idx)
	{
		if (a->arr[i] > max)
			return (0);
		max = a->arr[i];
		i++;
	}
	return (1);
}

int	log_base_ten_exp(int n)
{
	int	i;

	i = 1;
	while (abs(n) > 9)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

static int	read_op(char op[4])
{
	int	r;

	ft_memset(op, 0, 4);
	r = read(0, op, 3);
	if (r <= 0)
		return (0);
	while (op[2] != '\n' && op[3] != '\n')
		read(0, op + 3, 1);
	if (op[2] == '\n')
		op[2] = 0;
	else
		op[3] = 0;
	return (1);
}

static void	run_checker(t_stack *a, t_stack *b, int scale)
{
	char	op[4];

	while (read_op(op))
	{
		if (parse_op(a, b, op) < 0)
		{
			ft_printf("Error\n");
			free_stack(a);
			free_stack(b);
			exit(1);
		}
		if (IS_VISUAL)
			visual_bench(a, b, scale);
	}
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	int			scale;

	if (argc == 1)
		return (0);
	init_stack(&a);
	if (parse_stack_input(argv + 1, argc - 1, &a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	init_stack(&b);
	scale = log_base_ten_exp(get_max_value(&a));
	run_checker(&a, &b, scale);
	if (is_sorted(&a) && is_empty(&b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

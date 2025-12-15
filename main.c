/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:28:07 by sservant          #+#    #+#             */
/*   Updated: 2025/12/08 14:01:49 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i <= a->stack_top_idx)
	{
		j = i + 1;
		while (j <= a->stack_top_idx)
		{
			total_pairs += 1;
			if (a->arr[i] > a->arr[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	if (!total_pairs)
		return (-1);
	return (100 - ((mistakes * 100) / total_pairs));
}

static int	get_mode(int argc, char **argv, int *i, int *show_bench)
{
	int	mode;

	mode = MODE_ADAPTIVE;
	while (*i < argc && !ft_strncmp(argv[*i], "--", 2))
	{
		if (!ft_strncmp(argv[*i], "--bench", 8))
			*show_bench = 1;
		else if (!ft_strncmp(argv[*i], "--simple", 9))
			mode = MODE_SIMPLE;
		else if (!ft_strncmp(argv[*i], "--medium", 9))
			mode = MODE_MEDIUM;
		else if (!ft_strncmp(argv[*i], "--complex", 10))
			mode = MODE_COMPLEX;
		else if (!ft_strncmp(argv[*i], "--adaptive", 11))
			mode = MODE_ADAPTIVE;
		else
			return (1);
		(*i)++;
	}
	return (mode);
}

void	call_algo(t_stack *a, t_bench *bench)
{
	if (bench->mode == MODE_SIMPLE)
		simple_push_swap(a, bench);
	else if (bench->mode == MODE_MEDIUM)
		medium_push_swap(a, bench);
	else if (bench->mode == MODE_COMPLEX)
		complex_push_swap(a, bench);
	else if (bench->mode == MODE_ADAPTIVE)
		adaptive_push_swap(a, bench);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_bench	bench;
	int		show_bench;
	int		i;

	show_bench = 0;
	i = 1;
	if (!init_stack(&a) || argc == 1)
		return (argc != 1);
	init_bench(&bench);
	bench.mode = get_mode(argc, argv, &i, &show_bench);
	bench.strat = bench.mode;
	if ((argc - i) <= 0 || bench.mode == -1 || \
parse_stack_input(argv + i, argc - i, &a) \
|| a.stack_top_idx < 0)
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	bench.disorder = get_disorder(&a);
	if (bench.disorder > 0)
		call_algo(&a, &bench);
	if (show_bench)
		create_benchmark(&bench);
	free_stack(&a);
	return (0);
}
